/* Ghidra pseudocode, not original source.
 * ev_71ce34dfbc3e25ecc670a7014d4d5fe50c303635112430d697820e3c5a49cfb6
 * Entry: 0x5bc4a0; label: FUN_005bc4a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_005bc4a0(int param_1,int param_2)

{
  char cVar1;
  undefined4 *puVar2;
  
  if (param_1 == 0) {
    return 0;
  }
  if ((param_2 < *(char *)(param_1 + 1) + -1) && (0 < param_2)) {
    cVar1 = *(char *)(param_1 + 1) + -1;
    *(char *)(param_1 + 1) = cVar1;
    if (param_2 < cVar1) {
      puVar2 = (undefined4 *)(param_1 + 4 + param_2 * 4);
      do {
        param_2 = param_2 + 1;
        *puVar2 = puVar2[1];
        puVar2[8] = puVar2[9];
        puVar2 = puVar2 + 1;
      } while (param_2 < *(char *)(param_1 + 1));
    }
    return 1;
  }
  return 0;
}

