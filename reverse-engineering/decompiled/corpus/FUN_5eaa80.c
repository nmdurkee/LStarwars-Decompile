/* Ghidra analysis pseudocode, not original source.
 * ev_0c8ba0b3b7b14392dbbecf96693a80f9f750c2c118e50ed36c877e83d8a87913
 * Entry: 0x5eaa80; label: FUN_005eaa80
 */

void FUN_005eaa80(undefined4 param_1,undefined4 param_2)

{
  undefined *local_4;
  
  if (DAT_009738bc == 0) {
    DAT_009738bc = 1;
    local_4 = &DAT_00806cd0;
    DAT_009738b8 = FUN_005ea980(&local_4,param_1,param_2);
    if (DAT_009738b8 != 0) {
      *(undefined4 *)(DAT_009738b8 + 0x24) = 0x3f800000;
    }
  }
  return;
}

