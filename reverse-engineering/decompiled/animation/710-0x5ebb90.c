
void FUN_005ebb90(int param_1,int param_2,float param_3,int param_4,float param_5,undefined4 param_6
                 ,int param_7,undefined4 param_8,undefined4 param_9,undefined4 param_10,
                 undefined4 param_11)

{
  byte bVar1;
  byte bVar2;
  int iVar3;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined1 local_1c [12];
  undefined4 local_10;
  short local_c;
  uint local_8;
  undefined4 local_4;
  
  local_c = *(short *)(DAT_00973880 + 4);
  local_10 = 0;
  iVar3 = FUN_006de8d0((local_c + 1) * 0x30);
  local_8 = iVar3 + 0xfU & 0xfffffff0;
  local_4 = FUN_006de8d0((int)local_c);
  local_20 = 0;
  local_24 = 0;
  local_28 = 0;
  bVar1 = *(byte *)(param_2 + 0x13);
  bVar2 = *(byte *)(param_4 + 0x13);
  if (DAT_00973888 < 4) {
    (&DAT_0096e4e8)[DAT_00973888] = DAT_009737de;
    DAT_00973888 = DAT_00973888 + 1;
    DAT_009737de = (bVar1 | bVar2) & 1 | DAT_009737de;
  }
  else {
    FUN_005c12e0();
  }
  local_10 = *(undefined4 *)(param_1 + 0x168);
  FUN_005cc0d0(param_2,param_3 - 1.0,&local_10,local_10,0);
  local_10 = *(undefined4 *)(param_1 + 0x168);
  FUN_005cdd50(param_4,param_5 - 1.0,&local_10,param_6,local_10,0,local_1c);
  if ((param_7 != 0) && (DAT_00973884 != (code *)0x0)) {
    (*DAT_00973884)(&local_10,param_1,param_7,param_8);
  }
  FUN_005e9d90(&local_10,param_1,param_9,param_2,param_10,&local_28,param_11);
  FUN_006de960();
  FUN_006de960();
  iVar3 = DAT_00973888;
  if (DAT_00973888 != 0) {
    DAT_00973888 = DAT_00973888 + -1;
    DAT_009737de = *(undefined1 *)(iVar3 + 0x96e4e7);
    return;
  }
  FUN_005c12e0();
  return;
}

