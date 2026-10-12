/* Ghidra pseudocode, not original source.
 * ev_bef7beff20bbab7c70650c6f9f545113d8e67786c96c5ee03f6ff15c7c5049ec
 * Entry: 0x748130; label: FUN_00748130
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

uint FUN_00748130(uint param_1)

{
  char cVar1;
  
  cVar1 = FUN_00746f10(param_1,&param_1);
  return -(uint)(cVar1 != '\0') & param_1;
}

