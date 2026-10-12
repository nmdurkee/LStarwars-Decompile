/* Ghidra pseudocode, not original source.
 * ev_71ce34dfbc3e25ecc670a7014d4d5fe50c303635112430d697820e3c5a49cfb6
 * Entry: 0x5bcf50; label: FUN_005bcf50
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_005bcf50(char *param_1,int param_2)

{
  char cVar1;
  int iVar2;
  undefined4 *puVar3;
  char *pcVar4;
  int iVar5;
  
  if (param_1 != (char *)0x0) {
    FUN_005bcf00();
    if (DAT_0095e5dc == 0) {
      DAT_0095e5dc = FUN_004eef40(0x4b0,"d:\\projects\\legosagapc\\nu2api.saga\\numath\\nugraph.c",
                                  0x209);
    }
    if (DAT_0095e640 == 0) {
      DAT_0095e640 = FUN_004eef40(0x60,"d:\\projects\\legosagapc\\nu2api.saga\\numath\\nugraph.c",
                                  0x20e);
    }
    iVar2 = DAT_0095e640;
    if ((DAT_0095e5dc != 0) && (DAT_0095e640 != 0)) {
      if (100 < param_2) {
        param_2 = 100;
      }
      iVar5 = 0;
      DAT_0095e5d8 = param_2;
      if ('\0' < param_1[1]) {
        puVar3 = (undefined4 *)(DAT_0095e640 + 8);
        pcVar4 = param_1 + 0x24;
        do {
          iVar5 = iVar5 + 1;
          puVar3[-2] = *(undefined4 *)(pcVar4 + -0x20);
          puVar3[-1] = *(undefined4 *)pcVar4;
          *puVar3 = 0;
          puVar3 = puVar3 + 3;
          pcVar4 = pcVar4 + 4;
        } while (iVar5 < param_1[1]);
      }
      cVar1 = *param_1;
      if (cVar1 == '\0') {
        FUN_005bce50(param_1[1] + -1,iVar2,DAT_0095e5dc,param_2);
      }
      else {
        if (cVar1 == '\x01') {
          FUN_005bcda0(param_1[1] + -1,iVar2,DAT_0095e5dc,param_2);
          return 1;
        }
        if (cVar1 == '\x02') {
          FUN_005bccd0(param_1[1] + -1,3,iVar2,DAT_0095e5dc,param_2);
          return 1;
        }
      }
      return 1;
    }
  }
  return 0;
}

