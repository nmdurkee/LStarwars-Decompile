/* Ghidra analysis pseudocode, not original source.
 * ev_defa56967bea180293c2bb16677406271af3ce5a827b3a721aa49801cdb81f39
 * Entry: 0x6cc200; label: FUN_006cc200
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_006cc200(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_30 [16];
  undefined1 local_20 [28];
  
  FUN_006cb940(param_1,param_2);
  iVar1 = FUN_006ca2f0(local_30);
  if (iVar1 != 0) {
    FUN_0061e5d0(1);
    if (((*(byte *)(*(int *)(param_1 + 0x40) + 0x78) & 0x10) != 0) &&
       (DAT_008203d8 = DAT_008203d8 + 1, DAT_008203d8 == 4)) {
      DAT_008203d8 = 1;
    }
    if ((*(char *)(param_1 + 0x76) != '\0') && (*(float *)(param_1 + 0x1b0) != 0.0)) {
      FUN_0061e5d0(0);
      iVar1 = DAT_008203d8;
      FUN_00619190(*(undefined4 *)(param_1 + 0x40),DAT_008203d8);
      uVar2 = FUN_006e6b90();
      uVar2 = FUN_006cc020(param_1,param_2,uVar2,iVar1);
      return uVar2;
    }
    if ((*(char *)(param_1 + 0x53) != '\0') && (*(float *)(param_1 + 0x124) != 0.0)) {
      iVar1 = FUN_006c5190(param_1,local_30,local_20);
      _DAT_02973c1c = *(undefined4 *)(&DAT_0081f9b8 + iVar1 * 4);
      uVar2 = FUN_006cc020(param_1,param_2,*(undefined4 *)(in_ECX + 0x78),iVar1);
      return uVar2;
    }
  }
  return 0;
}

