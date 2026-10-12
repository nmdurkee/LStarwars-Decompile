/* Ghidra pseudocode, not original source.
 * ev_4955bd160544e7c7d97f773b8b388f36e51fe983a9fd069cd072b2ef5022de80
 * Entry: 0x504b10; label: FUN_00504b10
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 * FUN_00504b10(int param_1)

{
  char *pcVar1;
  char cVar2;
  char *pcVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  int *unaff_EDI;
  
  puVar5 = (undefined4 *)(*unaff_EDI + 0xfU & 0xfffffff0);
  *unaff_EDI = (int)(puVar5 + 3);
  *puVar5 = 0;
  puVar5[1] = 0;
  puVar5[2] = 0;
  FUN_004f7fb0(param_1);
  puVar5[1] = *unaff_EDI;
  pcVar3 = *(char **)(param_1 + 0x510);
  pcVar1 = pcVar3 + 1;
  do {
    cVar2 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar2 != '\0');
  *unaff_EDI = (int)(pcVar3 + *unaff_EDI + (1 - (int)pcVar1));
  _sprintf((char *)puVar5[1],*(char **)(param_1 + 0x510));
  uVar4 = FUN_00504100(param_1);
  puVar5[2] = uVar4;
  return puVar5;
}

