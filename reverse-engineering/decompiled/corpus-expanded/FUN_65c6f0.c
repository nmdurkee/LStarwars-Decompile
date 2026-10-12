/* Ghidra pseudocode, not original source.
 * ev_713fd5a551a5a644e53628cf932656c6d009da906ec29e05de784cd201c28f1f
 * Entry: 0x65c6f0; label: FUN_0065c6f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0065c6f0(char *param_1,undefined4 param_2)

{
  _strncpy(&DAT_029231b8 + DAT_02962944 * 0x14,param_1,0x10);
  (&DAT_029231c7)[DAT_02962944 * 0x14] = 0;
  *(undefined4 *)(&DAT_029231c8 + DAT_02962944 * 0x14) = param_2;
  DAT_02962944 = DAT_02962944 + 1;
  return;
}

