/* Ghidra pseudocode, not original source.
 * ev_d2059846c6c59f2eb69523c3226546ce784b50eedb8313b68b3d943803e3bded
 * Entry: 0x48ca80; label: FUN_0048ca80
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0048ca80(undefined4 param_1)

{
  undefined2 uVar1;
  
  uVar1 = FUN_004f9e70(param_1);
  *(undefined2 *)(DAT_00951b74 + 0xda) = uVar1;
  if (0x200 < *(ushort *)(DAT_00951b74 + 0xda)) {
    *(undefined2 *)(DAT_00951b74 + 0xda) = 0x200;
  }
  return;
}

