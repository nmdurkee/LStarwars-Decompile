/* Ghidra pseudocode, not original source.
 * ev_f26efce709548f397f112d14bef56d8f0f3486015c16e671b302622d1d4cb319
 * Entry: 0x650990; label: FUN_00650990
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00650990(int param_1)

{
  ushort *puVar1;
  ushort *puVar2;
  ushort *puVar3;
  
  puVar3 = &DAT_02921762;
  puVar2 = (ushort *)(param_1 + 4);
  do {
    puVar3[-1] = puVar3[-1] & puVar2[-2];
    *puVar3 = *puVar3 & puVar2[-1];
    puVar1 = (ushort *)(((int)&DAT_02921760 - param_1) + (int)puVar2);
    *puVar1 = *puVar1 & *puVar2;
    puVar1 = (ushort *)(((int)&DAT_02921762 - param_1) + (int)puVar2);
    *puVar1 = *puVar1 & puVar2[1];
    puVar1 = (ushort *)(((int)&DAT_02921764 - param_1) + (int)puVar2);
    *puVar1 = *puVar1 & puVar2[2];
    puVar3 = puVar3 + 5;
    puVar2 = puVar2 + 5;
  } while ((int)puVar3 < 0x292182a);
  return;
}

