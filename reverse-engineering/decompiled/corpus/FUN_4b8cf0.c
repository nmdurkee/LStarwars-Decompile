/* Ghidra analysis pseudocode, not original source.
 * ev_3ab0ab4bdd8dc8a455ed322812c7dbab6fd6000ce0d7a9019575e9409bf5a2c0
 * Entry: 0x4b8cf0; label: FUN_004b8cf0
 */

void FUN_004b8cf0(float param_1,int param_2,int param_3,float param_4,undefined4 *param_5)

{
  bool bVar1;
  int iVar2;
  ushort in_FPUControlWord;
  float local_2c;
  uint local_28;
  char local_24 [32];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_2c;
  if ((DAT_0093b324 == 0) ||
     ((*(int *)(PTR_DAT_00802c54 + 300) != 0 && (*(int *)(PTR_DAT_00802c54 + 300) == DAT_00951364)))
     ) {
    bVar1 = false;
    iVar2 = 0;
  }
  else {
    iVar2 = *(int *)(&DAT_007f9f5c + DAT_007fa198 * 4);
    bVar1 = true;
    if (((0 < iVar2) && (DAT_00879544 == iVar2 + -1)) && (DAT_009213e4 != 0)) goto LAB_004b8e07;
  }
  _sprintf(local_24,"%i",*param_5);
  local_28 = (uint)in_FPUControlWord;
  local_2c = (float)(int)ROUND((float)(byte)((-(param_2 != 0) & 0x60U) + 0x20) * param_4);
  FUN_0050c780(local_24,0xbc75c28f,param_1,0x3f800000,0x3f333333,0x3f333333,0x3f333333,8,0xff,0xff,
               0xff,(uint)local_2c & 0xff);
LAB_004b8e07:
  local_2c = (float)(int)ROUND(param_4 * 128.0);
  FUN_0050c780(&DAT_0075c044,0,param_1,0x3f800000,0x3f333333,0x3f333333,0x3f333333,0,0xff,0xbf,0,
               (uint)local_2c & 0xff);
  if (((!bVar1) || (iVar2 < 1)) || ((DAT_00879548 != iVar2 + -1 || (DAT_009213e4 == 0)))) {
    _sprintf(local_24,"%i",param_5[1]);
    local_2c = (float)(int)ROUND((float)(byte)((-(param_3 != 0) & 0x60U) + 0x20) * param_4);
    FUN_0050c780(local_24,0x3c75c28f,param_1,0x3f800000,0x3f333333,0x3f333333,0x3f333333,2,0xff,0xff
                 ,0xff,(uint)local_2c & 0xff);
  }
  if ((bVar1) && (0 < iVar2)) {
    _sprintf(local_24,"(%i)",iVar2);
    local_2c = param_1 - 0.125;
    FUN_0050c780(local_24,0,local_2c,0x3f800000,0x3f000000,0x3f000000,0x3f000000,0,0xff,0xff,0xff,
                 0x40);
  }
  __security_check_cookie(local_4 ^ (uint)&local_2c);
  return;
}

