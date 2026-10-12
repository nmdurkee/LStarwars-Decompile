/* Ghidra pseudocode, not original source.
 * ev_1b4e61f1467db5c8e431c69a2548c20deac6709d01307c3b7894b5c0724271ef
 * Entry: 0x522880; label: FUN_00522880
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00522880(char *param_1,uint param_2,undefined4 param_3,undefined4 param_4)

{
  char cVar1;
  char *pcVar2;
  uint *puVar3;
  char *extraout_ECX;
  int iVar4;
  int iVar5;
  undefined8 uVar6;
  
  if (param_1 != (char *)0x0) {
    pcVar2 = param_1;
    do {
      cVar1 = *pcVar2;
      pcVar2 = pcVar2 + 1;
    } while (cVar1 != '\0');
    if ((((uint)((int)pcVar2 - (int)(param_1 + 1)) < 0x40) && (param_2 != 0)) &&
       (DAT_00923914 < 0x20)) {
      iVar4 = DAT_00923914;
      if (0 < DAT_00923914) {
        puVar3 = &DAT_00923918;
        iVar5 = DAT_00923914;
        do {
          uVar6 = CONCAT44(iVar4,puVar3);
          if ((*puVar3 & param_2) != 0) {
            uVar6 = FUN_00512850();
            param_1 = extraout_ECX;
          }
          iVar4 = (int)((ulonglong)uVar6 >> 0x20);
          puVar3 = (uint *)((int)uVar6 + 0x4c);
          iVar5 = iVar5 + -1;
        } while (iVar5 != 0);
      }
      DAT_00923914 = iVar4 + 1;
      iVar5 = iVar4 * 0x4c - (int)param_1;
      do {
        cVar1 = *param_1;
        param_1[(int)(&DAT_00923920 + iVar5)] = cVar1;
        param_1 = param_1 + 1;
      } while (cVar1 != '\0');
      (&DAT_00923918)[iVar4 * 0x13] = param_2;
      (&DAT_0092391c)[iVar4 * 0x13] = param_3;
      *(undefined4 *)(&DAT_00923960 + iVar4 * 0x4c) = param_4;
      return;
    }
  }
  FUN_00512850();
  return;
}

