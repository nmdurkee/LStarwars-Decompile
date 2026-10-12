/* Ghidra analysis pseudocode, not original source.
 * ev_5e8001be3994efa046f160ea8bbb155dc91a9aa9b9ccef45a0e0570780a0cbe5
 * Entry: 0x541430; label: FUN_00541430
 */

void FUN_00541430(int *param_1,uint param_2)

{
  ushort *puVar1;
  
  if (((param_1 != (int *)0x0) && (param_2 < 0x40)) &&
     (puVar1 = (ushort *)(param_2 * 0x13c + 0x68 + *param_1),
     (*(ushort *)(param_2 * 0x13c + 0x68 + *param_1) & 0x100) != 0)) {
    *puVar1 = *puVar1 & 0xfeff;
  }
  return;
}

