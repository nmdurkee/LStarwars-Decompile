/* Ghidra pseudocode, not original source.
 * ev_5a6bf3c2990e6ac877664f285487eca7a15ac2a0f3d7c9cff5c7bd2adfae7eea
 * Entry: 0x4f6de0; label: FUN_004f6de0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

longlong FUN_004f6de0(int param_1,uint param_2,int param_3,int param_4)

{
  uint *puVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  longlong lVar6;
  
  if (0xfff < param_1) {
    iVar3 = FUN_006dee90(param_1 + -0x1000,param_2,param_4,0);
    return (longlong)iVar3;
  }
  if (0x3ff < param_1) {
    lVar6 = FUN_004f6c70(param_1,param_2,(int)param_2 >> 0x1f,param_4);
    return lVar6;
  }
  iVar3 = (param_1 + -1) * 0x40;
  if (*(int *)(&DAT_008ceb7c + iVar3) == 0) {
    lVar6 = FUN_004ff430(param_1 + -1,param_2,param_3,param_4);
    return lVar6;
  }
  if (param_4 != 1) {
    if (param_4 != 2) {
      *(uint *)(&DAT_008ceb58 + iVar3) = param_2;
      *(int *)(&DAT_008ceb5c + iVar3) = param_3;
      return CONCAT44(param_3,param_2);
    }
    iVar4 = *(uint *)(&DAT_008ceb68 + iVar3) - param_2;
    iVar5 = (*(int *)(&DAT_008ceb6c + iVar3) - param_3) -
            (uint)(*(uint *)(&DAT_008ceb68 + iVar3) < param_2);
    *(int *)(&DAT_008ceb58 + iVar3) = iVar4;
    *(int *)(&DAT_008ceb5c + iVar3) = iVar5;
    return CONCAT44(iVar5,iVar4);
  }
  puVar1 = (uint *)(&DAT_008ceb58 + iVar3);
  uVar2 = *puVar1;
  *puVar1 = *puVar1 + param_2;
  *(uint *)(&DAT_008ceb5c + iVar3) =
       *(int *)(&DAT_008ceb5c + iVar3) + param_3 + (uint)CARRY4(uVar2,param_2);
  return CONCAT44(*(undefined4 *)(&DAT_008ceb5c + iVar3),*(undefined4 *)(&DAT_008ceb58 + iVar3));
}

