/* Ghidra pseudocode, not original source.
 * ev_184291d84d57a0e0f71d3c8a05fa8a71135e786a990f62c870cdb26b01607f61
 * Entry: 0x60f440; label: FUN_0060f440
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0060f440(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)*DAT_02854d10;
  *puVar1 = param_1;
  puVar1[1] = param_2;
  *(undefined4 *)(*DAT_02854d10 + 8) = param_3;
  *DAT_02854d10 = *DAT_02854d10 + 0x18;
  DAT_02854d14 = DAT_02854d14 + 1;
  return;
}

