/* Ghidra analysis pseudocode, not original source.
 * ev_07efd457ec9a37501bdb802bda98d4fdf679445de954c80baf7ce8f2bb24f771
 * Entry: 0x6d4070; label: FUN_006d4070
 */

void FUN_006d4070(int param_1,void *param_2,int param_3,int param_4,undefined2 param_5)

{
  char cVar1;
  char cVar2;
  undefined1 uVar3;
  void *_Dst;
  undefined1 *puVar4;
  int iVar5;
  undefined4 uVar6;
  int in_ECX;
  int iVar7;
  void *pvVar8;
  char *pcVar9;
  
  _Dst = param_2;
  if (param_3 == 0) {
    iVar5 = param_1 * 0x17c + 0x4ea2;
  }
  else {
    iVar5 = param_4 * 0x80 + 0x6358;
  }
  puVar4 = (undefined1 *)((int)param_2 + 0x65);
  iVar7 = 8;
  do {
    puVar4[-1] = 0;
    *puVar4 = 0xff;
    puVar4[1] = 0xff;
    puVar4 = puVar4 + 3;
    iVar7 = iVar7 + -1;
  } while (iVar7 != 0);
  puVar4 = (undefined1 *)((int)param_2 + 0x7d);
  iVar7 = 0x10;
  do {
    puVar4[-1] = 0;
    *puVar4 = 0;
    puVar4 = puVar4 + 2;
    iVar7 = iVar7 + -1;
  } while (iVar7 != 0);
  if (0 < *(int *)(in_ECX + 0x67e4)) {
    pcVar9 = (char *)(in_ECX + 0x67f1);
    puVar4 = (undefined1 *)(iVar5 + in_ECX + 2);
    param_2 = (void *)0x0;
    do {
      iVar7 = (int)pcVar9[1];
      cVar1 = pcVar9[-1];
      iVar5 = (int)*pcVar9;
      cVar2 = puVar4[-2];
      if (cVar2 != '\0') {
        if (-1 < iVar5) {
          if ((cVar2 == '\f') || (cVar2 == '\r')) {
            *(char *)((int)_Dst + iVar5 * 3 + 100) = cVar2;
            uVar3 = *puVar4;
            *(undefined1 *)((int)_Dst + iVar5 * 3 + 0x65) = uVar3;
            *(undefined1 *)((int)_Dst + iVar5 * 3 + 0x66) = uVar3;
          }
          else if ((cVar2 == '\x02') || (cVar2 == '\x03')) {
            *(undefined1 *)((int)_Dst + iVar5 * 3 + 0x65) = *puVar4;
            *(undefined1 *)((int)_Dst + iVar5 * 3 + 0x66) = *puVar4;
            if (cVar1 == '\x03') {
              *(char *)((int)_Dst + iVar5 * 3 + 100) = (cVar2 != '\x02') + '\x02';
            }
            else {
              if (cVar1 == '\x02') {
                if (cVar2 == '\x02') {
LAB_006d4247:
                  *(undefined1 *)((int)_Dst + iVar5 * 3 + 100) = 2;
                  goto LAB_006d4268;
                }
              }
              else if ((cVar1 == '\x01') && (cVar2 == '\x03')) goto LAB_006d4247;
              *(undefined1 *)((int)_Dst + iVar5 * 3 + 100) = 3;
            }
          }
          else if ((cVar2 == '\x05') || (cVar2 == '\x06')) {
            *(undefined1 *)((int)_Dst + iVar5 * 3 + 0x65) = *puVar4;
            *(undefined1 *)((int)_Dst + iVar5 * 3 + 0x66) = *puVar4;
            if (cVar1 == '\x03') {
              *(char *)((int)_Dst + iVar5 * 3 + 100) = (cVar2 != '\x05') + '\x05';
            }
            else {
              if (cVar1 == '\x02') {
                if (cVar2 == '\x05') {
LAB_006d41ee:
                  *(undefined1 *)((int)_Dst + iVar5 * 3 + 100) = 5;
                  goto LAB_006d4268;
                }
              }
              else if ((cVar1 == '\x01') && (cVar2 == '\x06')) goto LAB_006d41ee;
              *(undefined1 *)((int)_Dst + iVar5 * 3 + 100) = 6;
            }
          }
          else {
            if (cVar2 == '\x01') {
              pvVar8 = (void *)((int)_Dst + iVar5 * 3);
              *(undefined1 *)((int)pvVar8 + 100) = 0xb;
            }
            else {
              if (cVar2 != '\a') goto LAB_006d4268;
              pvVar8 = (void *)((int)_Dst + iVar5 * 3);
              *(undefined1 *)((int)pvVar8 + 100) = 10;
            }
            if ((cVar1 == '\x02') || (cVar1 == '\x03')) {
              *(undefined1 *)((int)_Dst + iVar5 * 3 + 0x66) = *puVar4;
            }
            else {
              *(undefined1 *)((int)pvVar8 + 0x65) = *puVar4;
            }
          }
        }
LAB_006d4268:
        if ((-1 < iVar7) &&
           ((((((cVar2 == '\x02' || (cVar2 == '\x03')) || (cVar2 == '\x01')) ||
              ((cVar2 == '\a' || (cVar2 == '\x04')))) ||
             ((cVar2 == '\x05' || ((cVar2 == '\x06' || (cVar2 == '\f')))))) || (cVar2 == '\r')))) {
          *(char *)((int)_Dst + iVar7 * 2 + 0x7c) = cVar2;
          *(undefined1 *)((int)_Dst + iVar7 * 2 + 0x7d) = *puVar4;
        }
      }
      param_2 = (void *)((int)param_2 + 1);
      pcVar9 = pcVar9 + 6;
      puVar4 = puVar4 + 4;
    } while ((int)param_2 < *(int *)(in_ECX + 0x67e4));
  }
  pcVar9 = (char *)((int)_Dst + 0x66);
  iVar5 = 8;
  do {
    if ((pcVar9[-1] == -1) || (*pcVar9 == -1)) {
      pcVar9[-2] = '\0';
      *pcVar9 = '\0';
      pcVar9[-1] = '\0';
    }
    pcVar9 = pcVar9 + 3;
    iVar5 = iVar5 + -1;
  } while (iVar5 != 0);
  _memset(_Dst,0,0x40);
  iVar5 = param_1 * 0x17c + in_ECX;
  uVar6 = FUN_004f1ff0(iVar5 + 0x4e62);
  FUN_004ef660(_Dst,iVar5 + 0x4e62,uVar6);
  *(undefined4 *)((int)_Dst + 0x40) = *(undefined4 *)(iVar5 + 0x4e3c);
  *(uint *)((int)_Dst + 0x44) = (uint)*(ushort *)(iVar5 + 0x4e40);
  *(uint *)((int)_Dst + 0x48) = (uint)*(ushort *)(iVar5 + 0x4e42);
  *(undefined1 *)((int)_Dst + 0x4c) = *(undefined1 *)(iVar5 + 0x4e44);
  *(undefined1 *)((int)_Dst + 0x4d) = *(undefined1 *)(iVar5 + 0x4e45);
  *(undefined1 *)((int)_Dst + 0x4e) = *(undefined1 *)(iVar5 + 0x4e46);
  *(undefined1 *)((int)_Dst + 0x4f) = *(undefined1 *)(iVar5 + 0x4e47);
  *(undefined1 *)((int)_Dst + 0x50) = *(undefined1 *)(iVar5 + 0x4e48);
  *(undefined1 *)((int)_Dst + 0x51) = *(undefined1 *)(iVar5 + 0x4e49);
  *(undefined1 *)((int)_Dst + 0x52) = *(undefined1 *)(iVar5 + 0x4e4a);
  *(undefined1 *)((int)_Dst + 0x53) = *(undefined1 *)(iVar5 + 0x4e4b);
  *(undefined2 *)((int)_Dst + 0x54) = *(undefined2 *)(iVar5 + 0x4e4c);
  *(short *)((int)_Dst + 0x56) = (short)*(char *)(iVar5 + 0x4e4f);
  *(short *)((int)_Dst + 0x58) = (short)*(char *)(iVar5 + 0x4e4e);
  *(ushort *)((int)_Dst + 0x5a) = (ushort)*(byte *)(iVar5 + 0x4e50);
  *(ushort *)((int)_Dst + 0x5c) = (ushort)*(byte *)(iVar5 + 0x4e51);
  *(undefined2 *)((int)_Dst + 0x5e) = param_5;
  return;
}

