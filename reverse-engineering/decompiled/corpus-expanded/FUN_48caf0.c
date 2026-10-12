/* Ghidra pseudocode, not original source.
 * ev_d2059846c6c59f2eb69523c3226546ce784b50eedb8313b68b3d943803e3bded
 * Entry: 0x48caf0; label: FUN_0048caf0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0048caf0(undefined4 param_1)

{
  undefined1 uVar1;
  
  uVar1 = FUN_004f9e70(param_1);
  *(undefined1 *)(DAT_00951b74 + 0x100) = uVar1;
  if (0x40 < *(byte *)(DAT_00951b74 + 0x100)) {
    *(undefined1 *)(DAT_00951b74 + 0x100) = 0x40;
  }
  return;
}

