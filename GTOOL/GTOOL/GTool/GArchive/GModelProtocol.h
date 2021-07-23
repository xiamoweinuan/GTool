//
//  GModelProtocol.h
//  GTOOL
//
//  Created by gaoshuang on 2021/7/23.
//

#ifndef GModelProtocol_h
#define GModelProtocol_h


@protocol GModelProtocol <NSObject>
@optional
///父类赋值到子类，数据会被覆盖
-(void)g_convertForm:(GModel*)model;
@end


@protocol GDBModelProtocol <NSObject>

@optional
#pragma mark - 使用数据库储存需要设置
/// 生成表名 需要跟用户对应起来
+(NSString*)g_setTableNameMarker;
///根据表建立的模型
+(Class)g_setClassModelMarker;
///筛选需要记录的表中的属性，为nil表示全部记录
+(NSArray<NSString*>*)g_excludedProperties;
///表中增删改查，需要的标示，表示要取GModel中一个属性来，多策略查询需要重新修改方法
+(NSString*)g_setDBQueryMarker;

#pragma mark- 数据库储存提供的方法
///插入
+(void)g_dbInsert;
+(void)g_dbInsertWithWithModels:(NSArray<GModel*>*)models;
///删除
+(void)g_dbDel;
+(void)g_dbDelwithORQueryID:(NSString*)iD;
///更新
+(void)g_dbUpdate;
///查询
+(NSArray<GModel*>*)g_dbQueryALL;
+(NSArray<GModel*>*)g_dbQueryWithIDArray:(NSArray<NSString*>*)idArray;
///是否已经储存过了
+(BOOL)g_dbIsContain;
///需要切换表的时候
+(void)g_dbTableChangeBlock:(void (^)(void))block;
@end

@protocol GArchiveModelProtocol <NSObject>

@optional
#pragma mark - 使用归档储存需要设置
+(NSString*)g_setArchiveMarker;

#pragma mark- 归档储存提供的方法
//删除ArchiveModel
+(GModel*)g_archiveGet;
//删除ArchiveModel
+(void)g_archiveDel;
//更新ArchiveModel，可作为第一次赋值使用
+(__kindof GModel *)g_archiveUpdatewtihBlock:(void (^)(__kindof GModel* modelSub))block;
@end

#endif /* GModelProtocol_h */