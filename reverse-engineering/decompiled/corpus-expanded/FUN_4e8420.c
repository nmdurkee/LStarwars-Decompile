/* Ghidra pseudocode, not original source.
 * ev_0e37ff2b068f2f451a629821c3494056628992f54992bdfe8536c4096373c130
 * Entry: 0x4e8420; label: FUN_004e8420
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004e8420(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  DAT_00803bb4 = 0xffffffff;
  DAT_00803bb0 = 0xffffffff;
  iVar1 = FUN_005cf5b0(*(undefined4 *)(param_1 + 0x13c),&DAT_0087aad8,"pad_2_base_2",1);
  if ((iVar1 != 0) && (*(int *)(param_1 + 0x295c) != 0)) {
    uVar2 = FUN_005cffb0(&DAT_0087aad8);
    DAT_00803bb0 = FUN_0067c760(uVar2);
  }
  iVar1 = FUN_005cf5b0(*(undefined4 *)(param_1 + 0x13c),&DAT_0087aae4,"pad_4_base_2",1);
  if ((iVar1 != 0) && (*(int *)(param_1 + 0x295c) != 0)) {
    uVar2 = FUN_005cffb0(&DAT_0087aae4);
    DAT_00803bb4 = FUN_0067c760(uVar2);
  }
  return;
}

