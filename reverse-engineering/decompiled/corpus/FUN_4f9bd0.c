/* Ghidra analysis pseudocode, not original source.
 * ev_c6c5de14d13fb7351cb00798d8d33f42525c6eb06c0958f12186e2f5ad93dde9
 * Entry: 0x4f9bd0; label: FUN_004f9bd0
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_004f9bd0(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int extraout_EDX;
  undefined4 *puVar4;
  int iVar5;
  undefined8 uVar6;
  
  if (param_3 == 0) {
    iVar1 = FUN_004f9aa0(param_1,param_2);
    if ((-1 < iVar1) && (iVar1 = iVar1 * 0x10, *(int *)(*(int *)(param_1 + 8) + 4 + iVar1) != 0)) {
      iVar2 = FUN_004f0bd0();
      if (iVar2 == -1) {
        FUN_004ef7b0();
        return 0;
      }
      iVar3 = FUN_004f0c40(param_1,iVar2);
      if (iVar3 != -1) {
        puVar4 = (undefined4 *)((iVar3 + 3) * 0x10 + param_1);
        FUN_004f0cb0();
        iVar5 = iVar2 * 0x30;
        *(int *)(&DAT_0297dc60 + iVar5) = param_1;
        uVar6 = FUN_004f0a80(param_1,*(undefined4 *)(*(int *)(param_1 + 8) + iVar1));
        *(undefined8 *)(&DAT_0297dc68 + iVar5) = uVar6;
        *(undefined8 *)(&DAT_0297dc70 + iVar5) = uVar6;
        *(undefined4 *)(&DAT_0297dc78 + iVar5) = *(undefined4 *)(*(int *)(param_1 + 8) + 4 + iVar1);
        *(undefined4 *)(&DAT_0297dc7c + iVar5) = *(undefined4 *)(*(int *)(param_1 + 8) + 8 + iVar1);
        *(undefined4 *)(&DAT_0297dc88 + iVar5) =
             *(undefined4 *)(*(int *)(param_1 + 8) + 0xc + iVar1);
        *(int *)(&DAT_0297dc80 + iVar5) = iVar3;
        puVar4[2] = *(undefined4 *)(&DAT_0297dc70 + iVar5);
        puVar4[3] = *(undefined4 *)(&DAT_0297dc74 + iVar5);
        while( true ) {
          FUN_004f6de0(*puVar4,*(undefined4 *)(&DAT_0297dc68 + iVar5),
                       *(undefined4 *)(&DAT_0297dc6c + iVar5),0);
          if ((0 < extraout_EDX) || (-1 < extraout_EDX)) break;
          FUN_004ef7b0();
        }
        if (*(int *)(&DAT_0297dc88 + iVar5) == 2) {
          _DAT_0088ab40 = *(undefined4 *)(&DAT_0297dc68 + iVar5);
          _DAT_0088ab44 = *(undefined4 *)(&DAT_0297dc6c + iVar5);
          DAT_0090fba4 = 0;
          DAT_00917844 = puVar4;
          DAT_0091ce60 = (int *)(&DAT_0297dc60 + iVar5);
        }
        return iVar2 + 0x800;
      }
      (&DAT_0297dc84)[iVar2 * 0xc] = 0;
      return 0;
    }
    FUN_004ef7b0(param_2);
  }
  return 0;
}

