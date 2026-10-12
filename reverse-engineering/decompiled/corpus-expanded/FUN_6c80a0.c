/* Ghidra pseudocode, not original source.
 * ev_edb2d62139c6989f7d22bdb2eed4f22c2d5b161c90fb53b9f9b1b5e378e66a68
 * Entry: 0x6c80a0; label: FUN_006c80a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006c80a0(int param_1)

{
  uint uVar1;
  int *in_ECX;
  int unaff_EDI;
  undefined1 *puStack_120;
  undefined4 uStack_11c;
  undefined4 uStack_118;
  undefined1 local_108 [236];
  uint uStack_1c;
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)local_108;
  uStack_118 = 1;
  uStack_11c = 4;
  puStack_120 = local_108;
  (**(code **)(*in_ECX + 8))();
  uVar1 = local_4;
  if ((int)local_4 < unaff_EDI) {
    (**(code **)(*in_ECX + 8))(&stack0xfffffef0,1,0x100);
    FUN_004f1f40(param_1,&uStack_11c,uVar1);
    *(undefined1 *)(param_1 + -1 + uVar1) = 0;
    FUN_006b7c50(&uStack_11c,param_1);
  }
  else {
    (**(code **)(*in_ECX + 8))(param_1,1,unaff_EDI);
  }
  __security_check_cookie(uStack_1c ^ (uint)&puStack_120);
  return;
}

