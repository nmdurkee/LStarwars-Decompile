/* Ghidra analysis pseudocode, not original source.
 * ev_5e8001be3994efa046f160ea8bbb155dc91a9aa9b9ccef45a0e0570780a0cbe5
 * Entry: 0x5436e0; label: FUN_005436e0
 */

undefined1 * FUN_005436e0(undefined4 param_1)

{
  char *pcVar1;
  undefined *puVar2;
  int iVar3;
  char *pcVar4;
  uint uVar5;
  undefined4 *puVar6;
  undefined2 *puVar7;
  undefined4 *puVar8;
  
  FUN_006dd8c0(&DAT_009243f0);
  pcVar1 = (char *)0x9243ef;
  do {
    pcVar4 = pcVar1;
    pcVar1 = pcVar4 + 1;
  } while (pcVar4[1] != '\0');
  builtin_strncpy(pcVar4 + 1,"SavedGames",0xb);
  iVar3 = 0;
  do {
    pcVar1 = &DAT_009243f0 + iVar3;
    (&DAT_009245f0)[iVar3] = *pcVar1;
    puVar2 = PTR_s_GameTitle_0082761c;
    iVar3 = iVar3 + 1;
  } while (*pcVar1 != '\0');
  puVar7 = (undefined2 *)0x9245ef;
  do {
    pcVar1 = (char *)((int)puVar7 + 1);
    puVar7 = (undefined2 *)((int)puVar7 + 1);
  } while (*pcVar1 != '\0');
  *puVar7 = 0x5c;
  _sprintf((char *)&DAT_009246f8,"SaveGame%d.%s_SavedGame",param_1,puVar2);
  pcVar1 = (char *)&DAT_009246f8;
  do {
    pcVar4 = pcVar1;
    pcVar1 = pcVar4 + 1;
  } while (*pcVar4 != '\0');
  puVar8 = (undefined4 *)0x9245ef;
  do {
    pcVar1 = (char *)((int)puVar8 + 1);
    puVar8 = (undefined4 *)((int)puVar8 + 1);
  } while (*pcVar1 != '\0');
  puVar6 = &DAT_009246f8;
  for (uVar5 = (uint)(pcVar4 + -0x9246f7) >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
    *puVar8 = *puVar6;
    puVar6 = puVar6 + 1;
    puVar8 = puVar8 + 1;
  }
  for (uVar5 = (uint)(pcVar4 + -0x9246f7) & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
    *(undefined1 *)puVar8 = *(undefined1 *)puVar6;
    puVar6 = (undefined4 *)((int)puVar6 + 1);
    puVar8 = (undefined4 *)((int)puVar8 + 1);
  }
  return &DAT_009245f0;
}

