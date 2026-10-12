/* Ghidra pseudocode, not original source.
 * ev_01c84f1d9d20bf940b93d5cccd5d039a55498943f529f614c2585109312f1f15
 * Entry: 0x5788f0; label: FUN_005788f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

char * FUN_005788f0(undefined4 param_1,int *param_2,undefined4 param_3,int param_4,int *param_5,
                   code *param_6)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  char *pcVar5;
  char *pcVar6;
  char *pcVar7;
  undefined4 uVar8;
  
  iVar2 = FUN_004fc860(param_1);
  if (iVar2 == 0) {
    FUN_00578890(param_1);
  }
  DAT_00803b64 = param_4;
  pcVar5 = (char *)(*param_2 + 3U & 0xfffffffc);
  *param_2 = (int)pcVar5;
  iVar4 = 0;
  bVar1 = false;
  iVar3 = FUN_004fc5b0(iVar2);
  pcVar6 = pcVar5;
  do {
    if (iVar3 == 0) {
      FUN_004fa300(iVar2);
      if (iVar4 < 1) {
        FUN_00578890(param_1);
        return (char *)0x0;
      }
      *param_2 = (int)pcVar6;
      if (param_5 != (int *)0x0) {
        *param_5 = iVar4;
      }
      return pcVar5;
    }
    FUN_004f7fb0(iVar2);
    pcVar7 = *(char **)(iVar2 + 0x510);
    if (*pcVar7 != '\0') {
      if (bVar1) {
        iVar3 = FUN_004f8b10(pcVar7,"level_end");
        if (iVar3 == 0) {
          bVar1 = false;
          if (((*pcVar6 != '\0') && (pcVar6[0x40] != '\0')) &&
             ((*(uint *)(pcVar6 + 100) & 0x200) == 0)) {
            if ((*(uint *)(pcVar6 + 100) & 0x10000) != 0) {
              DAT_00951b8c = pcVar6;
            }
            if ((*(uint *)(pcVar6 + 100) & 0x20000) != 0) {
              DAT_00951b90 = pcVar6;
            }
            iVar4 = iVar4 + 1;
            pcVar6 = pcVar6 + 0x130;
          }
        }
        else {
          iVar3 = FUN_004f8b10(*(undefined4 *)(iVar2 + 0x510),&PTR_DAT_00761cc4);
          if (iVar3 == 0) {
            iVar3 = FUN_004f7fb0(iVar2);
            if ((iVar3 != 0) && (iVar3 = FUN_004f1ff0(*(undefined4 *)(iVar2 + 0x510)), iVar3 < 0x40)
               ) {
              uVar8 = *(undefined4 *)(iVar2 + 0x510);
              pcVar7 = pcVar6;
LAB_00578a4c:
              FUN_004f1f10(pcVar7,uVar8);
            }
          }
          else {
            iVar3 = FUN_004f8b10(*(undefined4 *)(iVar2 + 0x510),&DAT_00761cbc);
            if (((iVar3 == 0) && (iVar3 = FUN_004f7fb0(iVar2), iVar3 != 0)) &&
               (iVar3 = FUN_004f1ff0(*(undefined4 *)(iVar2 + 0x510)), iVar3 < 0x20)) {
              uVar8 = *(undefined4 *)(iVar2 + 0x510);
              pcVar7 = pcVar6 + 0x40;
              goto LAB_00578a4c;
            }
          }
          iVar3 = FUN_004f8b10(*(undefined4 *)(iVar2 + 0x510),"test_level");
          if (iVar3 == 0) {
            *(uint *)(pcVar6 + 100) = *(uint *)(pcVar6 + 100) | 0x200;
          }
          else {
            iVar3 = FUN_004f8b10(*(undefined4 *)(iVar2 + 0x510),"intro_level");
            if (iVar3 == 0) {
              *(uint *)(pcVar6 + 100) = *(uint *)(pcVar6 + 100) | 0x20;
            }
            else {
              iVar3 = FUN_004f8b10(*(undefined4 *)(iVar2 + 0x510),"midtro_level");
              if ((iVar3 == 0) ||
                 (iVar3 = FUN_004f8b10(*(undefined4 *)(iVar2 + 0x510),"cutscene_level"), iVar3 == 0)
                 ) {
                *(uint *)(pcVar6 + 100) = *(uint *)(pcVar6 + 100) | 0x40;
              }
              else {
                iVar3 = FUN_004f8b10(*(undefined4 *)(iVar2 + 0x510),"outro_level");
                if (iVar3 == 0) {
                  *(uint *)(pcVar6 + 100) = *(uint *)(pcVar6 + 100) | 0x80;
                }
                else {
                  iVar3 = FUN_004f8b10(*(undefined4 *)(iVar2 + 0x510),"status_level");
                  if (iVar3 == 0) {
                    *(uint *)(pcVar6 + 100) = *(uint *)(pcVar6 + 100) & 0xfffffff5 | 0x400;
                  }
                  else {
                    iVar3 = FUN_004f8b10(*(undefined4 *)(iVar2 + 0x510),"newgame_level");
                    if (iVar3 == 0) {
                      if (DAT_00951b8c == (char *)0x0) {
                        *(uint *)(pcVar6 + 100) = *(uint *)(pcVar6 + 100) | 0x10000;
                      }
                    }
                    else {
                      iVar3 = FUN_004f8b10(*(undefined4 *)(iVar2 + 0x510),"loadgame_level");
                      if ((iVar3 == 0) && (DAT_00951b90 == (char *)0x0)) {
                        *(uint *)(pcVar6 + 100) = *(uint *)(pcVar6 + 100) | 0x20000;
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
      else {
        iVar3 = FUN_004f8b10(pcVar7,"level_start");
        if ((iVar3 == 0) && (iVar4 < DAT_00803b64)) {
          pcVar6[0x84] = -0x33;
          pcVar6[0x85] = -0x34;
          pcVar6[0x86] = -0x34;
          pcVar6[0x87] = '=';
          pcVar6[0x60] = -1;
          pcVar6[0x61] = -1;
          pcVar6[0x94] = -1;
          pcVar6[0x95] = -1;
          pcVar6[0x88] = -0x66;
          pcVar6[0x89] = -0x67;
          pcVar6[0x8a] = '\x19';
          pcVar6[0x8b] = '>';
          pcVar6[0x96] = -1;
          pcVar6[0x97] = -1;
          pcVar6[0x9c] = -1;
          pcVar6[0x9d] = -1;
          pcVar6[0xa4] = '\0';
          pcVar6[0xa5] = '\0';
          pcVar6[0xa6] = '\0';
          pcVar6[0xa7] = '\0';
          pcVar6[0x9e] = -1;
          pcVar6[0x9f] = -1;
          pcVar6[0xa8] = '\0';
          pcVar6[0xa9] = '\0';
          pcVar6[0xaa] = '\0';
          pcVar6[0xab] = '\0';
          pcVar6[0xa2] = -1;
          pcVar6[0xa3] = -1;
          pcVar6[0xb4] = '\0';
          pcVar6[0xb5] = '\0';
          pcVar6[0xb6] = '\0';
          pcVar6[0xb7] = '?';
          pcVar6[200] = -1;
          pcVar6[0x118] = -1;
          pcVar6[0x119] = -1;
          pcVar6[0x11a] = -1;
          pcVar6[0x11b] = -1;
          pcVar6[0x120] = -1;
          pcVar6[0x121] = -1;
          pcVar6[0x122] = -1;
          pcVar6[0x123] = -1;
          pcVar6[0xb8] = '\0';
          pcVar6[0xb9] = '\0';
          pcVar6[0xba] = '\0';
          pcVar6[0xbb] = '\0';
          pcVar6[0x128] = -1;
          pcVar6[0x129] = -1;
          pcVar6[0x12a] = -1;
          pcVar6[299] = -1;
          pcVar6[0xbc] = '\0';
          pcVar6[0xbd] = '\0';
          pcVar6[0xbe] = '\0';
          pcVar6[0xbf] = '\0';
          pcVar6[0x11c] = -1;
          pcVar6[0x11d] = -1;
          pcVar6[0x11e] = -1;
          pcVar6[0x11f] = -1;
          pcVar6[0x124] = -1;
          pcVar6[0x125] = -1;
          pcVar6[0x126] = -1;
          pcVar6[0x127] = -1;
          pcVar6[0xc0] = '\0';
          pcVar6[0xc1] = '$';
          pcVar6[0xc2] = -0xc;
          pcVar6[0xc3] = 'I';
          pcVar6[300] = -1;
          pcVar6[0x12d] = -1;
          pcVar6[0x12e] = -1;
          pcVar6[0x12f] = -1;
          pcVar6[0xd0] = '\0';
          pcVar6[0xd1] = '\0';
          pcVar6[0xd2] = '\0';
          pcVar6[0xd3] = '\0';
          pcVar6[0xd4] = '\0';
          pcVar6[0xd5] = '\0';
          pcVar6[0xd6] = '\0';
          pcVar6[0xd7] = '\0';
          bVar1 = true;
          *pcVar6 = '\0';
          pcVar6[0x40] = '\0';
          *(short *)(pcVar6 + 0x62) = (short)iVar4;
          pcVar6[100] = '\x0e';
          pcVar6[0x65] = '\0';
          pcVar6[0x66] = '\0';
          pcVar6[0x67] = '\0';
          pcVar6[0x68] = '\0';
          pcVar6[0x69] = '\0';
          pcVar6[0x6a] = '\0';
          pcVar6[0x6b] = '\0';
          pcVar6[0x6c] = '\0';
          pcVar6[0x6d] = '\0';
          pcVar6[0x6e] = '\0';
          pcVar6[0x6f] = '\0';
          pcVar6[0x70] = '\0';
          pcVar6[0x71] = '\0';
          pcVar6[0x72] = '\0';
          pcVar6[0x73] = '\0';
          pcVar6[0x74] = '\0';
          pcVar6[0x75] = '\0';
          pcVar6[0x76] = '\0';
          pcVar6[0x77] = '\0';
          pcVar6[0x78] = '\0';
          pcVar6[0x79] = '\0';
          pcVar6[0x7a] = '\0';
          pcVar6[0x7b] = '\0';
          pcVar6[0x7c] = '\0';
          pcVar6[0x7d] = '\0';
          pcVar6[0x7e] = '\0';
          pcVar6[0x7f] = '\0';
          pcVar6[0x80] = '\0';
          pcVar6[0x81] = '\0';
          pcVar6[0x82] = '\0';
          pcVar6[0x83] = '\0';
          pcVar6[0x8c] = ' ';
          pcVar6[0x8d] = 'N';
          pcVar6[0x8f] = '\0';
          pcVar6[0x8e] = '\0';
          pcVar6[0x91] = '\0';
          pcVar6[0x90] = '\0';
          pcVar6[0x93] = '\0';
          pcVar6[0x92] = '\0';
          pcVar6[0x98] = -0x80;
          pcVar6[0x99] = '\0';
          pcVar6[0x9a] = '\0';
          pcVar6[0x9b] = '\x01';
          pcVar6[0xa0] = '\x03';
          pcVar6[0xa1] = '\x7f';
          pcVar6[0xac] = 'P';
          pcVar6[0xad] = 'P';
          pcVar6[0xae] = 'P';
          pcVar6[0xaf] = '2';
          pcVar6[0xb0] = '\0';
          pcVar6[0xb1] = '\0';
          pcVar6[0xb2] = '\0';
          pcVar6[0xb3] = '\0';
          pcVar6[0xc9] = '\x05';
          pcVar6[0xca] = '\n';
          pcVar6[0xcb] = '\x05';
          pcVar6[0xcc] = '\x05';
          pcVar6[0xcd] = '\n';
          pcVar6[0xce] = '\x05';
          pcVar6[0xcf] = '\x05';
          if (param_6 != (code *)0x0) {
            (*param_6)(pcVar6);
          }
        }
      }
    }
    iVar3 = FUN_004fc5b0(iVar2);
  } while( true );
}

