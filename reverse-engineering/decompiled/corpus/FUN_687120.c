/* Ghidra analysis pseudocode, not original source.
 * ev_58caf276ebc048efa4d646f9d9307ba49b402b8a20e2023011e3c4448b71b628
 * Entry: 0x687120; label: FUN_00687120
 */

void FUN_00687120(undefined4 param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  char *pcVar5;
  int iVar6;
  
  iVar2 = (&DAT_0292fe20)[DAT_02962010 * 0xb5];
  if ((iVar2 != 8) && (DAT_02924afc != -1)) {
    FUN_00659810(iVar2,param_1);
    iVar3 = DAT_02962010;
    iVar6 = DAT_02962010 * 0x2d4;
    iVar4 = DAT_02962010 * 0xb5 + iVar2;
    pcVar5 = (char *)0x0;
    (&DAT_02930018)[iVar4] = DAT_02924afc;
    (&DAT_02930038)[iVar4] = 1;
    do {
      cVar1 = *pcVar5;
      pcVar5[(int)(&DAT_0292ff98 + iVar6 + iVar2 * 0x10)] = cVar1;
      pcVar5 = pcVar5 + 1;
    } while (cVar1 != '\0');
    (&DAT_02930058)[iVar4] = 0x42480000;
    (&DAT_0292fe20)[iVar3 * 0xb5] = (&DAT_0292fe20)[iVar3 * 0xb5] + 1;
  }
  return;
}

