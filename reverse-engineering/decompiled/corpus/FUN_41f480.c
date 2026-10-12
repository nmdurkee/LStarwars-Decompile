/* Ghidra analysis pseudocode, not original source.
 * ev_fc46cff07f0ed537c3533760820ac45bd355561daa184f1b787f47d220e25ab8
 * Entry: 0x41f480; label: FUN_0041f480
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0041f480(void)

{
  code *pcVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  FUN_00596920(0);
  iVar6 = 0;
  iVar5 = DAT_0093d504;
  if (0 < DAT_0093d500) {
    do {
      if ((*(uint *)(iVar5 + 0x1f8) & 0x800) == 0) {
        if (*(char *)(iVar5 + 0x107c) == '\0') {
          iVar4 = 0;
        }
        else {
          iVar4 = iVar5 + 0x138;
        }
        if ((*(uint *)(iVar5 + 0xef0) & 0x20000) == 0) {
          iVar3 = 0;
        }
        else {
          iVar3 = iVar5 + 0xf8;
        }
        cVar2 = FUN_0041cb50(*(undefined4 *)(iVar5 + 0x50),iVar5 + 8,iVar5 + 0xb8,iVar3,iVar4,
                             iVar5 + 0x804,iVar5,*(undefined4 *)(iVar5 + 0x1048));
        *(char *)(iVar5 + 0x288) = cVar2;
        *(uint *)(iVar5 + 0xe24) =
             *(uint *)(iVar5 + 0xe24) ^ (DAT_02913108 * 8 ^ *(uint *)(iVar5 + 0xe24)) & 8;
        if (cVar2 == '\0') {
          if ((((((*(uint *)(iVar5 + 0xe20) & 0x400) != 0) || (*(char *)(iVar5 + 0x7b5) == '\b')) &&
               (0.0 < *(float *)(iVar5 + 0xd80))) &&
              ((0.0 < *(float *)(iVar5 + 0xd8c) &&
               (*(char *)(*(short *)(iVar5 + 0xe1e) * 0x10 + 0xe +
                         *(int *)(PTR_DAT_00802c54 + 0x2ac0)) != '\0')))) &&
             ((*(uint *)(*(int *)(*(int *)(iVar5 + 0x54) + 0x24) + 0x90) & 0x400) == 0)) {
            FUN_004a4ce0(iVar5 + 0xc68,*(undefined4 *)(iVar5 + 0xd8c),(int)*(short *)(iVar5 + 0xe1e)
                         ,*(float *)(iVar5 + 0xd80) / _DAT_007fc074,iVar5);
          }
        }
        else {
          FUN_0041e4c0(iVar5);
        }
        if (*(int *)(iVar5 + 0x10ac) != 0) {
          FUN_00597620(iVar5);
        }
        *(undefined1 *)(iVar5 + 0x28c) = 1;
        if (*(char *)(iVar5 + 0x288) != '\0') {
          *(uint *)(iVar5 + 0xef0) = *(uint *)(iVar5 + 0xef0) | 0x40000;
        }
        if ((DAT_0093b328 == 0) &&
           (pcVar1 = *(code **)(*(int *)(iVar5 + 0x54) + 0x20), pcVar1 != (code *)0x0)) {
          (*pcVar1)(iVar5);
        }
      }
      else if ((*(int *)(iVar5 + 0xcd0) != 0) && (*(char *)(iVar5 + 0x7b5) == ';')) {
        *(undefined1 *)(iVar5 + 0x288) = *(undefined1 *)(*(int *)(iVar5 + 0xcd0) + 0x288);
      }
      iVar6 = iVar6 + 1;
      iVar5 = iVar5 + 0x10d8;
    } while (iVar6 < DAT_0093d500);
  }
  thunk_FUN_005d05b0();
  return;
}

