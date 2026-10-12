/* Ghidra pseudocode, not original source.
 * ev_d2059846c6c59f2eb69523c3226546ce784b50eedb8313b68b3d943803e3bded
 * Entry: 0x48c9d0; label: FUN_0048c9d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0048c9d0(undefined4 param_1)

{
  undefined1 uVar1;
  
  uVar1 = FUN_004f9e70(param_1);
  *(undefined1 *)(DAT_00951b74 + 0xf2) = uVar1;
  if (8 < *(byte *)(DAT_00951b74 + 0xf2)) {
    *(undefined1 *)(DAT_00951b74 + 0xf2) = 8;
  }
  return;
}

