/* Ghidra pseudocode, not original source.
 * ev_c1426acf87a342a1866e519dab13ac5b40d9f4eac6e37fcdd4b99f9d53dd1e8b
 * Entry: 0x6d45f0; label: FUN_006d45f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006d45f0(int param_1,int param_2,undefined4 param_3,int param_4,int param_5)

{
  int iVar1;
  byte bVar2;
  byte bVar3;
  undefined1 uVar4;
  int iVar5;
  int in_ECX;
  uint uVar6;
  int iVar7;
  ushort *puVar8;
  char *pcVar9;
  ushort uVar10;
  
  if (param_4 == 0) {
    iVar7 = param_2 * 0x17c + 0x4ea2;
  }
  else {
    *(int *)(in_ECX + 0x6558 + param_5 * 4) = param_2;
    iVar7 = param_5 * 0x80 + 0x6358;
  }
  iVar7 = iVar7 + in_ECX;
  iVar1 = param_2 * 0x17c + in_ECX;
  *(bool *)(iVar1 + 0x4e60) = param_1 != 0;
  *(undefined1 *)(iVar1 + 0x4e5e) = 0;
  iVar5 = 0;
  do {
    *(undefined1 *)(iVar7 + iVar5 * 4) = 0;
    *(undefined2 *)(iVar7 + 2 + iVar5 * 4) = 0;
    iVar5 = iVar5 + 1;
  } while (iVar5 < 0x20);
  if (param_1 != 0) {
    *(undefined1 *)(iVar1 + 0x4e5f) = 1;
    if (param_4 == 0) {
      *(undefined1 *)(iVar1 + 0x4e50) = *(undefined1 *)(param_1 + 0x5a);
      *(undefined1 *)(iVar1 + 0x4e51) = *(undefined1 *)(param_1 + 0x5c);
    }
    puVar8 = (ushort *)(iVar7 + 2);
    pcVar9 = (char *)(in_ECX + 0x67f0);
    param_2 = 0x20;
    do {
      if (*pcVar9 != '\0') {
        iVar7 = (int)pcVar9[1];
        uVar6 = (uint)pcVar9[2];
        if (-1 < iVar7) {
          iVar1 = param_1 + iVar7 * 2;
          bVar2 = *(byte *)(iVar7 + iVar1 + 100);
          bVar3 = *(byte *)(iVar7 * 3 + param_1 + 0x66);
          if (bVar2 - 2 < 0xc) {
            uVar10 = (ushort)*(byte *)(iVar7 + 0x65 + iVar1);
            switch(bVar2) {
            default:
              *(byte *)(puVar8 + -1) = bVar2;
LAB_006d4709:
              *puVar8 = (ushort)bVar3;
              break;
            case 4:
            case 7:
            case 8:
            case 9:
              break;
            case 10:
              *(undefined1 *)(puVar8 + -1) = 7;
              if (*pcVar9 == '\x02') goto LAB_006d4709;
              *puVar8 = uVar10;
              break;
            case 0xb:
              *(undefined1 *)(puVar8 + -1) = 1;
              if (*pcVar9 == '\x02') goto LAB_006d4709;
              *puVar8 = uVar10;
            }
          }
        }
        if ((uVar6 < 0x10) && ((char)puVar8[-1] == '\0')) {
          uVar4 = *(undefined1 *)(param_1 + 0x7c + uVar6 * 2);
          bVar2 = *(byte *)(param_1 + 0x7d + uVar6 * 2);
          switch(uVar4) {
          case 1:
          case 2:
          case 3:
          case 4:
          case 5:
          case 6:
          case 7:
            *(undefined1 *)(puVar8 + -1) = uVar4;
            *puVar8 = (ushort)bVar2;
          }
        }
      }
      pcVar9 = pcVar9 + 6;
      puVar8 = puVar8 + 2;
      param_2 = param_2 + -1;
    } while (param_2 != 0);
  }
  return;
}

