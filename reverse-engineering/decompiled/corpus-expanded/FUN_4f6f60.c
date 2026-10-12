/* Ghidra pseudocode, not original source.
 * ev_5a6bf3c2990e6ac877664f285487eca7a15ac2a0f3d7c9cff5c7bd2adfae7eea
 * Entry: 0x4f6f60; label: FUN_004f6f60
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004f6f60(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 local_c;
  longlong local_8;
  
  iVar1 = param_1;
  iVar3 = DAT_00800468 + -1;
  local_c = 0;
  DAT_00800468 = iVar3;
  local_8 = FUN_004f6d10(param_1);
  param_1 = (int)local_8 - (&DAT_00918e68)[iVar3 * 4];
  iVar2 = DAT_0080046c - param_1 % DAT_0080046c;
  if (iVar2 != DAT_0080046c) {
    local_8 = local_8 + iVar2;
    param_1 = param_1 + iVar2;
    if (iVar1 < 0x1000) {
      if (iVar1 < 0x400) {
        FUN_004ff3f0(iVar1 + -1,&local_c,iVar2);
      }
      else {
        FUN_004f0380(iVar1,&local_c);
      }
    }
    else {
      FUN_006dee60(iVar1 + -0x1000,&local_c,iVar2,0);
    }
  }
  if ((int)(&DAT_00918e64)[iVar3 * 4] < 0) {
    param_1 = -param_1;
  }
  FUN_004f6de0(iVar1,(&DAT_00918e68)[iVar3 * 4] + 4,
               (&DAT_00918e6c)[iVar3 * 4] + (uint)(0xfffffffb < (uint)(&DAT_00918e68)[iVar3 * 4]),0)
  ;
  if (iVar1 < 0x1000) {
    if (iVar1 < 0x400) {
      FUN_004ff3f0(iVar1 + -1,&param_1,4);
    }
    else {
      FUN_004f0380(iVar1,&param_1);
    }
  }
  else {
    FUN_006dee60(iVar1 + -0x1000,&param_1,4,0);
  }
  FUN_004f6de0(iVar1,local_8,0);
  return;
}

