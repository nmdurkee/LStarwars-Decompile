/* Ghidra pseudocode, not original source.
 * ev_be2e1b76976fde28c062f4f0fb6ba1ce818a6b2c78af6ba8f2a77520ff39bb32
 * Entry: 0x57aff0; label: FUN_0057aff0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0057aff0(int param_1)

{
  undefined2 uVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar2 = FUN_004f7fb0(param_1);
  if (iVar2 != 0) {
    uVar1 = FUN_00548a60(*(undefined4 *)(param_1 + 0x510),DAT_009248cc,0xffffffff);
    *(undefined2 *)(DAT_00951c4c + 0xea) = uVar1;
    uVar3 = FUN_00694320(0x10,*(undefined4 *)(param_1 + 0x510));
    *(undefined4 *)(DAT_00951c4c + 0x18c) = uVar3;
  }
  return;
}

