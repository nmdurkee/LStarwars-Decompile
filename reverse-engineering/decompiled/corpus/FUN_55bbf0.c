/* Ghidra analysis pseudocode, not original source.
 * ev_7885ce39b81f670d8e3218fe7ff5fd78bd200dfae790f8ac5e62a68993a50c0e
 * Entry: 0x55bbf0; label: FUN_0055bbf0
 */

void FUN_0055bbf0(int *param_1)

{
  int iVar1;
  
  DAT_0093b280 = param_1;
  DAT_0093b26c = 0;
  if (param_1 != (int *)0x0) {
    iVar1 = *param_1;
    while (iVar1 != 0) {
      DAT_0093b26c = DAT_0093b26c + 1;
      param_1 = param_1 + 3;
      iVar1 = *param_1;
    }
  }
  return;
}

