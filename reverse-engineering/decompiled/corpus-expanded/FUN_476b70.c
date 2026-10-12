/* Ghidra pseudocode, not original source.
 * ev_d7259de4d528e446adcf31e3fd20dda0be8e8c3eebc020039674bf2429a30a4e
 * Entry: 0x476b70; label: FUN_00476b70
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00476b70(void)

{
  undefined2 uVar1;
  undefined2 *puVar2;
  undefined4 *puVar3;
  
  puVar3 = &DAT_00879b60;
  puVar2 = &DAT_00879b58;
  do {
    uVar1 = FUN_0054fa60();
    *puVar2 = uVar1;
    *puVar3 = 0;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  } while ((int)puVar2 < 0x879b60);
  return;
}

