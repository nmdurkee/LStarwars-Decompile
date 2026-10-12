/* Ghidra analysis pseudocode, not original source.
 * ev_142c6a8c6383f125e012f2efba2eadfa5dbe8b6e60e30e9e06bfa3e419522019
 * Entry: 0x6193e0; label: FUN_006193e0
 */

void FUN_006193e0(undefined4 *param_1,undefined4 *param_2)

{
  byte bVar1;
  
  if (param_2[6] != 0) {
    for (param_1 = (undefined4 *)*param_1; param_1 != (undefined4 *)0x0;
        param_1 = (undefined4 *)*param_1) {
      if (param_1 == param_2) {
        if (param_1[2] == 3) {
          bVar1 = *(byte *)((int)param_1 + 0x11);
          *(byte *)((int)param_1 + 0x11) = (-bVar1 - 1 ^ bVar1) & 1 ^ bVar1;
        }
        else {
          *(byte *)((int)param_1 + 0x11) = *(byte *)((int)param_1 + 0x11) | 1;
        }
      }
      else if (param_1[6] == param_2[6]) {
        *(byte *)((int)param_1 + 0x11) = *(byte *)((int)param_1 + 0x11) & 0xfe;
      }
    }
  }
  return;
}

