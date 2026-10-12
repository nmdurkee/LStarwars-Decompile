/* Ghidra pseudocode, not original source.
 * ev_d2059846c6c59f2eb69523c3226546ce784b50eedb8313b68b3d943803e3bded
 * Entry: 0x48cac0; label: FUN_0048cac0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0048cac0(undefined4 param_1)

{
  undefined1 uVar1;
  
  uVar1 = FUN_004f9e70(param_1);
  *(undefined1 *)(DAT_00951b74 + 0xff) = uVar1;
  if (0x10 < *(byte *)(DAT_00951b74 + 0xff)) {
    *(undefined1 *)(DAT_00951b74 + 0xff) = 0x10;
  }
  return;
}

