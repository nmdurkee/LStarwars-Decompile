/* Ghidra pseudocode, not original source.
 * ev_e349fb5d4996fa1cecd3bcddaaa967a101a71b87d72fe496b907a3d03e81288d
 * Entry: 0x60dd00; label: FUN_0060dd00
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0060dd00(void)

{
  undefined4 uVar1;
  int in_ECX;
  
  FUN_005c8f10();
  uVar1 = FUN_0060d9b0(2,&DAT_007675b0,&DAT_00767708);
  *(undefined4 *)(in_ECX + 0x10) = uVar1;
  uVar1 = FUN_0060d9b0(2,&DAT_007675b0,&DAT_00767fe0);
  *(undefined4 *)(in_ECX + 0x14) = uVar1;
  uVar1 = FUN_0060d9b0(2,&DAT_00768d38,&DAT_00768888);
  *(undefined4 *)(in_ECX + 0x18) = uVar1;
  uVar1 = FUN_0060d9b0(2,&DAT_00768d38,&DAT_00768af8);
  *(undefined4 *)(in_ECX + 0x1c) = uVar1;
  return;
}

