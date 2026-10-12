/* Ghidra analysis pseudocode, not original source.
 * ev_fb3e2efa05f3fdcad8ac13641a8f1821f73d708273cedf9c40d68478f4bf822c
 * Entry: 0x575240; label: FUN_00575240
 */

void FUN_00575240(int param_1,undefined4 param_2)

{
  bool bVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  undefined1 *puVar5;
  
  *(undefined4 *)(param_1 + 0x4698) = 0;
  if ((*(int *)(param_1 + 0x13c) != 0) && (iVar3 = FUN_004fc900("doors",param_2,0xffff), iVar3 != 0)
     ) {
    puVar5 = (undefined1 *)(*(int *)(param_1 + 0x104) + 3U & 0xfffffffc);
    *(undefined1 **)(param_1 + 0x104) = puVar5;
    *(undefined1 **)(param_1 + 0x4698) = puVar5;
    FUN_004f10e0(iVar3,&PTR_s_spline_00803878);
    bVar1 = false;
    iVar4 = FUN_004fc5b0(iVar3);
    while (iVar4 != 0) {
      iVar4 = FUN_004f7fb0(iVar3);
      if (iVar4 != 0) {
        if (bVar1) {
          iVar4 = FUN_004f8b10(*(undefined4 *)(iVar3 + 0x510),"door_end");
          if (iVar4 == 0) {
            bVar1 = false;
            if ((*(int *)(puVar5 + 0xa0) != 0) && (*(short *)(puVar5 + 0xf0) != -1)) {
              if (*(short *)(puVar5 + 0xf2) == -1) {
                *(short *)(puVar5 + 0xf2) = *(short *)(puVar5 + 0xf0);
              }
              puVar5 = puVar5 + 0x128;
              *(int *)(param_1 + 0x469c) = *(int *)(param_1 + 0x469c) + 1;
            }
          }
          else {
            FUN_004fa020(iVar3);
          }
        }
        else {
          iVar4 = FUN_004f8b10(*(undefined4 *)(iVar3 + 0x510),"door_start");
          if (iVar4 == 0) {
            *puVar5 = 0;
            puVar5[0x80] = 0;
            *(undefined4 *)(puVar5 + 0xa0) = 0;
            *(undefined4 *)(puVar5 + 0xd4) = DAT_0093b0cc;
            *(undefined4 *)(puVar5 + 0xd8) = DAT_0093b0d0;
            uVar2 = DAT_0093b0d4;
            *(undefined4 *)(puVar5 + 0xe0) = 0x3f800000;
            *(undefined4 *)(puVar5 + 0xdc) = uVar2;
            *(undefined4 *)(puVar5 + 0xe4) = DAT_0080250c;
            *(undefined4 *)(puVar5 + 0xe8) = DAT_00802510;
            uVar2 = DAT_00802514;
            *(undefined4 *)(puVar5 + 0xfc) = 0;
            *(undefined4 *)(puVar5 + 0x100) = 0x3f800000;
            bVar1 = true;
            DAT_009513b4 = param_1;
            DAT_00951398 = puVar5;
            *(undefined4 *)(puVar5 + 0xec) = uVar2;
            *(undefined2 *)(puVar5 + 0xf0) = 0xffff;
            *(undefined2 *)(puVar5 + 0xf2) = 0xffff;
            puVar5[0xf4] = 0xff;
            puVar5[0xf5] = 0;
            puVar5[0xf6] = 0xff;
            puVar5[0xf7] = 0;
            *(undefined4 *)(puVar5 + 0xf8) = 0;
            *(undefined4 *)(puVar5 + 0x108) = 0;
            *(undefined4 *)(puVar5 + 0x10c) = 0;
          }
        }
      }
      iVar4 = FUN_004fc5b0(iVar3);
    }
    FUN_004fa300(iVar3);
    if (0 < *(int *)(param_1 + 0x469c)) {
      *(uint *)(param_1 + 0x104) = (uint)(puVar5 + 0xf) & 0xfffffff0;
      return;
    }
    *(undefined4 *)(param_1 + 0x4698) = 0;
  }
  return;
}

