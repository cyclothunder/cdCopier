#include <QStorageInfo>
#include <QDebug>

#include "utils.h"

utils::utils()
{

}

utils::~utils()
{

}


QStringList utils::getROList_devices()
{

    QStringList ret;

    foreach (const QStorageInfo &storage, QStorageInfo::mountedVolumes()){
        if (storage.isValid() && storage.isReady()) {
            if (storage.isReadOnly()) {

               ret << storage.device();
              }
         }
     }

     return ret;
}

//QStringList utils::getROList_displayNames()
//{

//    QStringList ret;

//    foreach (const QStorageInfo &storage, QStorageInfo::mountedVolumes()){
//        if (storage.isValid() && storage.isReady()) {
//            if (storage.isReadOnly()) {

//                ret << storage.device();

//              }
//         }
//     }

//     ret << "/dev/another_device";
//     return ret;
//}

//QStringList utils::getROList_size()
//{

//    QStringList ret;

//    foreach (const QStorageInfo &storage, QStorageInfo::mountedVolumes()){
//        if (storage.isValid() && storage.isReady()) {
//            if (storage.isReadOnly()) {

//                ret << (storage.bytesTotal() / 1024); // Conver bytes to megabytes

//              }
//         }
//     }

//     ret << "/dev/another_device";
//     return ret;
//}
