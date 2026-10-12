/* Ghidra pseudocode, not original source.
 * ev_001bae53855cec29a6ea9336ea11e15c4e661e4f9ad78accb3ab39ae90f716fb
 * Entry: 0x61f870; label: FUN_0061f870
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_0061f870(int param_1)

{
  if (param_1 != 0) {
    if ((((*(byte *)(param_1 + 0x92) < 0x40) || (0xc0 < *(byte *)(param_1 + 0x92))) ||
        (*(byte *)(param_1 + 0x93) < 0x40)) || (0xc0 < *(byte *)(param_1 + 0x93))) {
      return 1;
    }
    if (((*(byte *)(param_1 + 0x90) < 0x40) || (0xc0 < *(byte *)(param_1 + 0x90))) ||
       ((*(byte *)(param_1 + 0x91) < 0x40 || (0xc0 < *(byte *)(param_1 + 0x91))))) {
      return 2;
    }
  }
  return 0;
}

