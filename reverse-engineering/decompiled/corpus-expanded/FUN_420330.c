/* Ghidra pseudocode, not original source.
 * ev_55c731fbd74135d460c444c417a3a15a2648f8ead34d22c2fd0b5dd9a411012b
 * Entry: 0x420330; label: FUN_00420330
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00420330(void)

{
  undefined4 uVar1;
  int in_ECX;
  float *pfVar2;
  int iVar3;
  undefined4 local_8;
  
  uVar1 = FUN_006d6800();
  local_8 = (undefined4)(longlong)ROUND(*(float *)(in_ECX + 0x98));
  uVar1 = FUN_006d6810(uVar1,local_8);
  pfVar2 = (float *)(in_ECX + 0x78);
  iVar3 = 4;
  do {
    local_8 = (undefined4)(longlong)ROUND(*pfVar2);
    uVar1 = FUN_006d6810(uVar1,local_8);
    pfVar2 = pfVar2 + 1;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  return;
}

