/* Ghidra pseudocode, not original source.
 * ev_fbd0714d29abf1967b7a59c1140afabe8eda1c53d580ba604e59c833adf58051
 * Entry: 0x619520; label: FUN_00619520
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_00619520(undefined4 param_1)

{
  int unaff_ESI;
  int unaff_EDI;
  
  if ((*(byte *)(unaff_EDI + 0x78) & 0x40) == 0) {
    if (((*(uint *)(unaff_EDI + 0x70) & 0x40) != 0) && (*(code **)(unaff_ESI + 0x50) != (code *)0x0)
       ) {
      (**(code **)(unaff_ESI + 0x50))(param_1);
    }
  }
  else {
    FUN_006193e0(param_1);
    if (*(code **)(unaff_ESI + 0x4c) != (code *)0x0) {
      (**(code **)(unaff_ESI + 0x4c))(param_1);
      return 0;
    }
  }
  return 0;
}

