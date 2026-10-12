/* Ghidra pseudocode, not original source.
 * ev_e04dcb01310c2b6a71419ceaaf6429f586bcd28525a19be66005014cd18274f1
 * Entry: 0x74b2a0; label: FUN_0074b2a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_0074b2a0(char *param_1)

{
  int iVar1;
  char *pcVar2;
  char *pcVar3;
  bool bVar4;
  
  iVar1 = 3;
  bVar4 = true;
  pcVar2 = param_1;
  pcVar3 = "&&";
  do {
    if (iVar1 == 0) break;
    iVar1 = iVar1 + -1;
    bVar4 = *pcVar2 == *pcVar3;
    pcVar2 = pcVar2 + 1;
    pcVar3 = pcVar3 + 1;
  } while (bVar4);
  if (!bVar4) {
    iVar1 = 3;
    bVar4 = true;
    pcVar2 = param_1;
    pcVar3 = "||";
    do {
      if (iVar1 == 0) break;
      iVar1 = iVar1 + -1;
      bVar4 = *pcVar2 == *pcVar3;
      pcVar2 = pcVar2 + 1;
      pcVar3 = pcVar3 + 1;
    } while (bVar4);
    if (!bVar4) {
      iVar1 = 3;
      bVar4 = true;
      pcVar2 = param_1;
      pcVar3 = "==";
      do {
        if (iVar1 == 0) break;
        iVar1 = iVar1 + -1;
        bVar4 = *pcVar2 == *pcVar3;
        pcVar2 = pcVar2 + 1;
        pcVar3 = pcVar3 + 1;
      } while (bVar4);
      if (!bVar4) {
        iVar1 = 3;
        bVar4 = true;
        pcVar2 = param_1;
        pcVar3 = "<=";
        do {
          if (iVar1 == 0) break;
          iVar1 = iVar1 + -1;
          bVar4 = *pcVar2 == *pcVar3;
          pcVar2 = pcVar2 + 1;
          pcVar3 = pcVar3 + 1;
        } while (bVar4);
        if (!bVar4) {
          iVar1 = 3;
          bVar4 = true;
          pcVar2 = param_1;
          pcVar3 = ">=";
          do {
            if (iVar1 == 0) break;
            iVar1 = iVar1 + -1;
            bVar4 = *pcVar2 == *pcVar3;
            pcVar2 = pcVar2 + 1;
            pcVar3 = pcVar3 + 1;
          } while (bVar4);
          if (!bVar4) {
            iVar1 = 2;
            bVar4 = true;
            pcVar2 = param_1;
            pcVar3 = "<";
            do {
              if (iVar1 == 0) break;
              iVar1 = iVar1 + -1;
              bVar4 = *pcVar2 == *pcVar3;
              pcVar2 = pcVar2 + 1;
              pcVar3 = pcVar3 + 1;
            } while (bVar4);
            if (!bVar4) {
              iVar1 = 2;
              bVar4 = true;
              pcVar2 = param_1;
              pcVar3 = ">";
              do {
                if (iVar1 == 0) break;
                iVar1 = iVar1 + -1;
                bVar4 = *pcVar2 == *pcVar3;
                pcVar2 = pcVar2 + 1;
                pcVar3 = pcVar3 + 1;
              } while (bVar4);
              if (!bVar4) {
                iVar1 = 3;
                bVar4 = true;
                pcVar2 = param_1;
                pcVar3 = "!=";
                do {
                  if (iVar1 == 0) break;
                  iVar1 = iVar1 + -1;
                  bVar4 = *pcVar2 == *pcVar3;
                  pcVar2 = pcVar2 + 1;
                  pcVar3 = pcVar3 + 1;
                } while (bVar4);
                if (!bVar4) {
                  iVar1 = 2;
                  bVar4 = true;
                  pcVar2 = param_1;
                  pcVar3 = "!";
                  do {
                    if (iVar1 == 0) break;
                    iVar1 = iVar1 + -1;
                    bVar4 = *pcVar2 == *pcVar3;
                    pcVar2 = pcVar2 + 1;
                    pcVar3 = pcVar3 + 1;
                  } while (bVar4);
                  if (bVar4) {
                    return 3;
                  }
                  iVar1 = 8;
                  bVar4 = true;
                  pcVar2 = param_1;
                  pcVar3 = "defined";
                  do {
                    if (iVar1 == 0) break;
                    iVar1 = iVar1 + -1;
                    bVar4 = *pcVar2 == *pcVar3;
                    pcVar2 = pcVar2 + 1;
                    pcVar3 = pcVar3 + 1;
                  } while (bVar4);
                  if (bVar4) {
                    return 4;
                  }
                  bVar4 = true;
                  iVar1 = 2;
                  pcVar2 = &DAT_007e9624;
                  do {
                    if (iVar1 == 0) break;
                    iVar1 = iVar1 + -1;
                    bVar4 = *param_1 == *pcVar2;
                    param_1 = param_1 + 1;
                    pcVar2 = pcVar2 + 1;
                  } while (bVar4);
                  return (!bVar4 - 1 & 0xfffffc22) + 1000;
                }
              }
            }
          }
        }
      }
      return 2;
    }
  }
  return 1;
}

