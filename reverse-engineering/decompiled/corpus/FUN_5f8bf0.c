/* Ghidra analysis pseudocode, not original source.
 * ev_a85358c7a67f9df9af49bd13a9e5d6f2df9e1c4faca93f034535aa61df0d1386
 * Entry: 0x5f8bf0; label: FUN_005f8bf0
 */

void FUN_005f8bf0(int param_1)

{
  if ((DAT_02854bc4 != param_1) || ((param_1 != 0 && (*(int *)(param_1 + 0xa0) != 0)))) {
    if (param_1 == DAT_02854bc8) {
      FUN_006e33a0();
    }
    else if (param_1 == DAT_02854bcc) {
      FUN_006e3650();
    }
    else if (param_1 != 0) {
      FUN_006e3720(param_1,0);
      FUN_006e3720(param_1 + 0x1c,1);
      FUN_006e3720(param_1 + 0x38,2);
      FUN_006e3720(param_1 + 0x54,3);
      FUN_006e2260(param_1 + 0x70);
    }
    DAT_02854bc4 = param_1;
    if (param_1 != 0) {
      *(undefined4 *)(param_1 + 0xa0) = 1;
    }
  }
  return;
}

