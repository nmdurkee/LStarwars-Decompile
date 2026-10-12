/* Ghidra pseudocode, not original source.
 * ev_df72e9ec6d097d98265581ff35a2e461cddfe69d3931fceba3802c9eedcc8d52
 * Entry: 0x63e000; label: FUN_0063e000
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0063e000(undefined4 param_1,undefined4 param_2)

{
  undefined4 *in_ECX;
  
  in_ECX[6] = param_1;
  *in_ECX = &PTR_FUN_0076bd7c;
  in_ECX[7] = param_2;
  in_ECX[4] = DAT_02973ab4;
  in_ECX[5] = &DAT_0076bd70;
  return;
}

