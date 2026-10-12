/* Ghidra pseudocode, not original source.
 * ev_5a6bf3c2990e6ac877664f285487eca7a15ac2a0f3d7c9cff5c7bd2adfae7eea
 * Entry: 0x4f6ea0; label: FUN_004f6ea0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004f6ea0(undefined4 param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  longlong lVar4;
  
  iVar3 = DAT_00800464 + -1;
  DAT_00800464 = iVar3;
  lVar4 = FUN_004f6d10(param_1);
  uVar1 = (&DAT_0090ffac)[iVar3 * 4];
  iVar2 = uVar1 + (&DAT_0090ffb0)[iVar3 * 4];
  iVar3 = ((int)uVar1 >> 0x1f) + (&DAT_0090ffb4)[iVar3 * 4] +
          (uint)CARRY4(uVar1,(&DAT_0090ffb0)[iVar3 * 4]);
  if (lVar4 != CONCAT44(iVar3,iVar2)) {
    FUN_004f6de0(param_1,iVar2,iVar3,0);
  }
  return;
}

