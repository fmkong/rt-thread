#include <rtconfig.h>
#if defined(PKG_USING_FAL)
#include <fal.h>
#include <dfs_fs.h>
#include "fal_cfg.h"

#define DBG_SECTION_NAME               "mnt"
#define DBG_LEVEL                      DBG_INFO
#include <rtdbg.h>

#if defined(BSP_USING_QSPI_FLASH)

#define FS_PARTITION_NAME              FS_EXT_NOR_FLASH_PARTITION_NAME

int fal_fs_init(void)
{
    struct rt_device *mtd_dev = RT_NULL;

    fal_init();
    LOG_I("Create a mtd device on partition '%s'.", FS_PARTITION_NAME);
    mtd_dev = fal_mtd_nor_device_create(FS_PARTITION_NAME);
    if (!mtd_dev) {
        LOG_E("Can't create a mtd device on partition '%s'.", FS_PARTITION_NAME);
    } else {
        LOG_I("Mount on partition '%s' to path %s.", FS_PARTITION_NAME, "/");
        if (dfs_mount(FS_PARTITION_NAME, "/", "lfs", 0, 0) == 0) {
            LOG_I("Filesystem initialized %s!", FS_PARTITION_NAME);
        } else {
            LOG_I("Mkfs and Mount on partition '%s'.", FS_PARTITION_NAME);
            dfs_mkfs("lfs", FS_PARTITION_NAME);
            if (dfs_mount(FS_PARTITION_NAME, "/", "lfs", 0, 0) == 0) {
                LOG_I("Filesystem initialized %s!", FS_PARTITION_NAME);
            } else {
                LOG_E("Failed to initialize filesystem!");
            }
        }
    }
    return RT_EOK;
}

INIT_ENV_EXPORT(fal_fs_init);

#endif /* BSP_USING_OSPI_FLASH */
#endif /* PKG_USING_FAL */