/* Ghidra pseudocode, not original source.
 * ev_f26efce709548f397f112d14bef56d8f0f3486015c16e671b302622d1d4cb319
 * Entry: 0x650890; label: FUN_00650890
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00650890(int param_1,int param_2)

{
  ushort *puVar1;
  ushort *puVar2;
  int iVar3;
  
  puVar2 = (ushort *)(param_2 + 6);
  puVar1 = (ushort *)(param_1 + 2);
  iVar3 = 0x14;
  do {
    puVar1[-1] = puVar1[-1] & puVar2[-3];
    *puVar1 = *puVar1 & *(ushort *)((param_2 - param_1) + (int)puVar1);
    puVar1[1] = puVar1[1] & puVar2[-1];
    puVar1[2] = puVar1[2] & *puVar2;
    puVar1[3] = puVar1[3] & puVar2[1];
    puVar1 = puVar1 + 5;
    puVar2 = puVar2 + 5;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  return;
}

