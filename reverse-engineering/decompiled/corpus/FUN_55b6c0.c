/* Ghidra analysis pseudocode, not original source.
 * ev_7885ce39b81f670d8e3218fe7ff5fd78bd200dfae790f8ac5e62a68993a50c0e
 * Entry: 0x55b6c0; label: FUN_0055b6c0
 */

undefined4 FUN_0055b6c0(int param_1)

{
  if ((-1 < param_1) && (param_1 < DAT_0093b278)) {
    return *(undefined4 *)(DAT_0093b270 + param_1 * 4);
  }
  return 0;
}

