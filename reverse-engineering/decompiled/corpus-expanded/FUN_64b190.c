/* Ghidra pseudocode, not original source.
 * ev_1ed2ee538169644958bcf6b45e609dd0f8f5843391a9d69ffaf951ca25289b49
 * Entry: 0x64b190; label: FUN_0064b190
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_0064b190(int param_1)

{
  if (-1 < param_1) {
    return (float10)((float)(&DAT_02913b50)[param_1 * 0x5e] + (float)(&DAT_02913b4c)[param_1 * 0x5e]
                    );
  }
  return (float10)0;
}

