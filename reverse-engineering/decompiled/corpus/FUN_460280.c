/* Ghidra analysis pseudocode, not original source.
 * ev_5f3da693bf096313253939ed49ba5271cfe8862e4a440ae5c9d57980f69a0d69
 * Entry: 0x460280; label: FUN_00460280
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00460280(int param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  float10 extraout_ST0;
  float10 fVar4;
  float fVar5;
  
  if ((param_3 != 0) && (0 < *(int *)(param_1 + 0x14))) {
    if ((*(float *)(param_1 + 0x18) < 1.0) ||
       (*(float *)(param_1 + 0x1c) - 1.0 <= *(float *)(param_1 + 0x18))) {
      iVar1 = FUN_006e6b90();
      fVar5 = (float)(&DAT_029899a0)[iVar1 >> 1 & 0x7fff];
    }
    else {
      fVar5 = 1.0;
    }
    uVar2 = FUN_006e6b90(fVar5);
    FUN_0050d910(*(undefined4 *)(DAT_00926c20 + DAT_00880728 * 4),0,0x3d4ccccd,(float)extraout_ST0,
                 _DAT_007f85f8,_DAT_007f85f8,_DAT_007f85f8,0,(undefined1)DAT_007fa4c8,
                 (undefined1)DAT_007fa4cc,(undefined1)DAT_0087a774,0x3fd9999a,1,0,0,uVar2);
    fVar4 = (float10)FUN_005b7d30(_DAT_00925028,0x40800000);
    uVar3 = (int)ROUND(fVar4 * (float10)0.25 * (float10)65536.0) & 0xffff;
    FUN_00552d10(0,fVar5 - 1.5,0x3f800000,0x3f800000,0x3f800000,0x3f800000,
                 (int)ROUND((float)(&DAT_029899a0)[(int)(uVar3 * 2) >> 1 & 0x7fff] * 1820.0) &
                 0xffff,uVar3,0,*(int *)(PTR_DAT_00802c54 + 0x2ac0) + 0xd20,2);
    FUN_0050d910(*(undefined4 *)
                  (DAT_00926c20 +
                  *(short *)(&PTR_DAT_007f3d9c)[*(char *)(*(int *)(param_2 + 0x14) + 0x7e) * 8] * 4)
                 ,0,fVar5 * -1.0 + 1.5,0x3f800000,_DAT_007f85f8,_DAT_007f85f8,_DAT_007f85f8,0,0xff,
                 0xff,0xff,0x3fd9999a,1,0,0,0x80);
  }
  return;
}

