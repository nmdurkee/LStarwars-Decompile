/* Ghidra pseudocode, not original source.
 * ev_e04dcb01310c2b6a71419ceaaf6429f586bcd28525a19be66005014cd18274f1
 * Entry: 0x74b240; label: FUN_0074b240
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

uint FUN_0074b240(int *param_1,uint *param_2)

{
  char cVar1;
  uint uVar2;
  
  uVar2 = 0;
  if (0 < param_1[1]) {
    do {
      cVar1 = *(char *)(*param_1 + uVar2);
      if ((cVar1 != ' ') && (cVar1 != '\t')) {
        if (cVar1 == '#') {
          *param_2 = uVar2;
          return CONCAT31((int3)(uVar2 >> 8),1);
        }
        break;
      }
      uVar2 = uVar2 + 1;
    } while ((int)uVar2 < param_1[1]);
  }
  return uVar2 & 0xffffff00;
}

