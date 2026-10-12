/* Ghidra pseudocode, not original source.
 * ev_bef7beff20bbab7c70650c6f9f545113d8e67786c96c5ee03f6ff15c7c5049ec
 * Entry: 0x746f10; label: FUN_00746f10
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_00746f10(int *param_1,uint *param_2)

{
  int *piVar1;
  uint *puVar2;
  char cVar3;
  int iVar4;
  char *pcVar5;
  char *pcVar6;
  int iVar7;
  char *pcVar8;
  bool bVar9;
  int *local_4;
  
  puVar2 = param_2;
  pcVar5 = (char *)param_1[2];
  iVar4 = 8;
  bVar9 = true;
  pcVar6 = pcVar5;
  pcVar8 = "defined";
  do {
    piVar1 = param_1;
    if (iVar4 == 0) break;
    iVar4 = iVar4 + -1;
    bVar9 = *pcVar6 == *pcVar8;
    pcVar6 = pcVar6 + 1;
    pcVar8 = pcVar8 + 1;
  } while (bVar9);
  do {
    if (bVar9) {
      iVar4 = FUN_00746bb0(*(undefined4 *)(*(int *)*piVar1 + 8));
      *param_2 = (uint)(iVar4 != 0);
      return 1;
    }
    iVar4 = 2;
    bVar9 = true;
    pcVar6 = &DAT_007e9624;
    do {
      if (iVar4 == 0) break;
      iVar4 = iVar4 + -1;
      bVar9 = *pcVar5 == *pcVar6;
      pcVar5 = pcVar5 + 1;
      pcVar6 = pcVar6 + 1;
    } while (bVar9);
    if (!bVar9) {
      pcVar5 = (char *)piVar1[2];
      iVar4 = 2;
      bVar9 = true;
      pcVar6 = pcVar5;
      pcVar8 = "!";
      break;
    }
    piVar1 = (int *)*piVar1;
    pcVar5 = (char *)piVar1[2];
    iVar4 = 8;
    bVar9 = true;
    pcVar6 = pcVar5;
    pcVar8 = "defined";
    do {
      if (iVar4 == 0) break;
      iVar4 = iVar4 + -1;
      bVar9 = *pcVar6 == *pcVar8;
      pcVar6 = pcVar6 + 1;
      pcVar8 = pcVar8 + 1;
    } while (bVar9);
  } while( true );
  while( true ) {
    iVar4 = iVar4 + -1;
    bVar9 = *pcVar6 == *pcVar8;
    pcVar6 = pcVar6 + 1;
    pcVar8 = pcVar8 + 1;
    if (!bVar9) break;
    if (iVar4 == 0) break;
  }
  if (bVar9) {
    cVar3 = FUN_00746f10(*piVar1,param_2);
    if (cVar3 != '\0') {
      *puVar2 = (uint)(*puVar2 == 0);
      return 1;
    }
  }
  else {
    iVar4 = 3;
    bVar9 = true;
    pcVar6 = pcVar5;
    pcVar8 = "&&";
    do {
      if (iVar4 == 0) break;
      iVar4 = iVar4 + -1;
      bVar9 = *pcVar6 == *pcVar8;
      pcVar6 = pcVar6 + 1;
      pcVar8 = pcVar8 + 1;
    } while (bVar9);
    if (bVar9) {
      cVar3 = FUN_00746f10(*piVar1,&param_1);
      if ((cVar3 != '\0') && (cVar3 = FUN_00746f10(piVar1[1],&local_4), cVar3 != '\0')) {
        if ((param_1 != (int *)0x0) && (local_4 != (int *)0x0)) {
          *param_2 = 1;
          return 1;
        }
        *param_2 = 0;
        return 1;
      }
    }
    else {
      iVar4 = 3;
      bVar9 = true;
      pcVar6 = pcVar5;
      pcVar8 = "||";
      do {
        if (iVar4 == 0) break;
        iVar4 = iVar4 + -1;
        bVar9 = *pcVar6 == *pcVar8;
        pcVar6 = pcVar6 + 1;
        pcVar8 = pcVar8 + 1;
      } while (bVar9);
      if (bVar9) {
        cVar3 = FUN_00746f10(*piVar1,&param_1);
        if ((cVar3 != '\0') && (param_1 != (int *)0x0)) {
LAB_00747304:
          *param_2 = (uint)param_1;
          return 1;
        }
        cVar3 = FUN_00746f10(piVar1[1],&local_4);
        if (cVar3 != '\0') {
          *param_2 = (uint)local_4;
          return 1;
        }
      }
      else {
        iVar4 = 3;
        bVar9 = true;
        pcVar6 = pcVar5;
        pcVar8 = "==";
        do {
          if (iVar4 == 0) break;
          iVar4 = iVar4 + -1;
          bVar9 = *pcVar6 == *pcVar8;
          pcVar6 = pcVar6 + 1;
          pcVar8 = pcVar8 + 1;
        } while (bVar9);
        if (bVar9) {
          cVar3 = FUN_00746f10(*piVar1,&param_1);
          if ((cVar3 != '\0') && (cVar3 = FUN_00746f10(piVar1[1],&local_4), cVar3 != '\0')) {
            *param_2 = (uint)(param_1 == local_4);
            return 1;
          }
        }
        else {
          iVar4 = 3;
          bVar9 = true;
          pcVar6 = pcVar5;
          pcVar8 = "<=";
          do {
            if (iVar4 == 0) break;
            iVar4 = iVar4 + -1;
            bVar9 = *pcVar6 == *pcVar8;
            pcVar6 = pcVar6 + 1;
            pcVar8 = pcVar8 + 1;
          } while (bVar9);
          if (bVar9) {
            cVar3 = FUN_00746f10(*piVar1,&param_1);
            if ((cVar3 != '\0') && (cVar3 = FUN_00746f10(piVar1[1],&local_4), cVar3 != '\0')) {
              *param_2 = (uint)((int)param_1 <= (int)local_4);
              return 1;
            }
          }
          else {
            iVar4 = 3;
            bVar9 = true;
            pcVar6 = pcVar5;
            pcVar8 = ">=";
            do {
              if (iVar4 == 0) break;
              iVar4 = iVar4 + -1;
              bVar9 = *pcVar6 == *pcVar8;
              pcVar6 = pcVar6 + 1;
              pcVar8 = pcVar8 + 1;
            } while (bVar9);
            if (bVar9) {
              cVar3 = FUN_00746f10(*piVar1,&param_1);
              if ((cVar3 != '\0') && (cVar3 = FUN_00746f10(piVar1[1],&local_4), cVar3 != '\0')) {
                *param_2 = (uint)((int)local_4 <= (int)param_1);
                return 1;
              }
            }
            else {
              iVar4 = 2;
              bVar9 = true;
              pcVar6 = pcVar5;
              pcVar8 = "<";
              do {
                if (iVar4 == 0) break;
                iVar4 = iVar4 + -1;
                bVar9 = *pcVar6 == *pcVar8;
                pcVar6 = pcVar6 + 1;
                pcVar8 = pcVar8 + 1;
              } while (bVar9);
              if (bVar9) {
                cVar3 = FUN_00746f10(*piVar1,&param_1);
                if ((cVar3 != '\0') && (cVar3 = FUN_00746f10(piVar1[1],&local_4), cVar3 != '\0')) {
                  *param_2 = (uint)((int)param_1 < (int)local_4);
                  return 1;
                }
              }
              else {
                iVar4 = 2;
                bVar9 = true;
                pcVar6 = pcVar5;
                pcVar8 = ">";
                do {
                  if (iVar4 == 0) break;
                  iVar4 = iVar4 + -1;
                  bVar9 = *pcVar6 == *pcVar8;
                  pcVar6 = pcVar6 + 1;
                  pcVar8 = pcVar8 + 1;
                } while (bVar9);
                if (bVar9) {
                  cVar3 = FUN_00746f10(*piVar1,&param_1);
                  if ((cVar3 != '\0') && (cVar3 = FUN_00746f10(piVar1[1],&local_4), cVar3 != '\0'))
                  {
                    *param_2 = (uint)((int)local_4 < (int)param_1);
                    return 1;
                  }
                }
                else {
                  iVar4 = 3;
                  bVar9 = true;
                  pcVar6 = pcVar5;
                  pcVar8 = "!=";
                  do {
                    if (iVar4 == 0) break;
                    iVar4 = iVar4 + -1;
                    bVar9 = *pcVar6 == *pcVar8;
                    pcVar6 = pcVar6 + 1;
                    pcVar8 = pcVar8 + 1;
                  } while (bVar9);
                  if (bVar9) {
                    cVar3 = FUN_00746f10(*piVar1,&param_1);
                    if ((cVar3 != '\0') && (cVar3 = FUN_00746f10(piVar1[1],&local_4), cVar3 != '\0')
                       ) {
                      *param_2 = (uint)(param_1 != local_4);
                      return 1;
                    }
                  }
                  else {
                    iVar4 = FUN_00746bb0(pcVar5);
                    if (iVar4 == 0) {
                      iVar4 = piVar1[2];
                    }
                    else {
                      do {
                        iVar7 = iVar4;
                        iVar4 = FUN_00746bb0(*(undefined4 *)(iVar7 + 4));
                      } while (iVar4 != 0);
                      iVar4 = *(int *)(iVar7 + 4);
                    }
                    if ((iVar4 != 0) && (cVar3 = FUN_00746900(iVar4), cVar3 != '\0')) {
                      param_1 = (int *)FUN_004f29a0(iVar4);
                      goto LAB_00747304;
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  return 0;
}

