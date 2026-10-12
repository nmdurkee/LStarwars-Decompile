/* Ghidra analysis pseudocode, not original source.
 * ev_0d221f2c9357ed308f9b597510bd130964f67481868d3ff45e1443ef5eb3d7b9
 * Entry: 0x6253f0; label: FUN_006253f0
 */

undefined4 FUN_006253f0(undefined4 param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  char *pcVar5;
  int unaff_ESI;
  uint local_4;
  
  if ((*(byte *)(unaff_ESI + 0x4c) & 1) != 0) {
    iVar2 = FUN_004f1ff0(&DAT_02900b70);
    if (DAT_0080f59c < 0) {
      DAT_0080f59c = 0;
    }
    if (iVar2 < DAT_0080f59c) {
      DAT_0080f59c = iVar2;
    }
    iVar3 = FUN_006d6940(&local_4);
    if (iVar3 != -1) {
      switch(iVar3) {
      default:
        cVar1 = FUN_0061e6b0(iVar3,local_4 & 1);
        if (cVar1 != '\0') {
          pcVar4 = &DAT_02900b70 + DAT_0080f59c;
          (&DAT_02900b71)[iVar2] = 0;
          for (pcVar5 = &DAT_02900b70 + iVar2; pcVar4 < pcVar5; pcVar5 = pcVar5 + -1) {
            *pcVar5 = pcVar5[-1];
          }
          DAT_0080f59c = DAT_0080f59c + 1;
          *pcVar5 = cVar1;
        }
        break;
      case 0xe:
        if (0 < DAT_0080f59c) {
          iVar2 = DAT_0080f59c + -1;
          pcVar4 = &DAT_02900b6f + DAT_0080f59c;
          pcVar5 = &DAT_02900b6f + DAT_0080f59c;
          DAT_0080f59c = iVar2;
          if (*pcVar4 != '\0') {
            do {
              *pcVar5 = pcVar5[1];
              pcVar5 = pcVar5 + 1;
            } while (*pcVar5 != '\0');
            return 0;
          }
        }
        break;
      case 0x1c:
        FUN_0061e530();
        if (*(code **)(unaff_ESI + 0x78) != (code *)0x0) {
          (**(code **)(unaff_ESI + 0x78))(param_1);
        }
      case 1:
        *(uint *)(unaff_ESI + 0x4c) = *(uint *)(unaff_ESI + 0x4c) & 0xfffffffe;
        DAT_0080f59c = 0xffffffff;
        return 0;
      case 0xcb:
        if (0 < DAT_0080f59c) {
          DAT_0080f59c = DAT_0080f59c + -1;
          return 0;
        }
        break;
      case 0xcd:
        if (DAT_0080f59c < iVar2) {
          DAT_0080f59c = DAT_0080f59c + 1;
          return 0;
        }
        break;
      case 0xd3:
        if ((DAT_0080f59c < iVar2) &&
           (pcVar4 = &DAT_02900b70 + DAT_0080f59c, (&DAT_02900b70)[DAT_0080f59c] != '\0')) {
          do {
            *pcVar4 = pcVar4[1];
            pcVar4 = pcVar4 + 1;
          } while (*pcVar4 != '\0');
          return 0;
        }
      }
    }
  }
  return 0;
}

