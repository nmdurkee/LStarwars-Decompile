/* Ghidra analysis pseudocode, not original source.
 * ev_cadbdcea344f284c720862a9d60fea326d89961e952df44594a2f8e4339e7270
 * Entry: 0x52cc90; label: FUN_0052cc90
 */

void FUN_0052cc90(int param_1,undefined4 param_2,int param_3,int *param_4,float param_5)

{
  float fVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  bool bVar7;
  undefined4 uVar8;
  
  puVar3 = param_4;
  if (param_4 == (undefined4 *)0x0) {
    return;
  }
  if (param_4[1] == 0) {
    return;
  }
  iVar6 = 0;
  param_4[9] = (int)((float)param_4[9] + param_5);
  if (0 < param_4[0x19]) {
    param_4 = param_4 + 0x15;
    do {
      iVar2 = *param_4;
      iVar4 = FUN_004f1440(iVar2 + 0x1c);
      if ((iVar4 != 0) && (iVar4 = FUN_0052c880(param_1,iVar2 + 0x1c,param_3,puVar3), iVar4 == 0)) {
        puVar3[0x19] = iVar6;
        if (iVar6 == 0) {
          if (*(byte *)(param_3 + 0x138) == 0xff) {
            iVar6 = 0;
          }
          else {
            iVar6 = (uint)*(byte *)(param_3 + 0x138) * 0xa4 + *(int *)(param_1 + 0x18);
          }
          uVar5 = *(undefined4 *)(iVar2 + 0x14);
          uVar8 = *puVar3;
        }
        else {
          uVar5 = *(undefined4 *)(iVar2 + 0x14);
          uVar8 = *(undefined4 *)(puVar3[iVar6 + 0x14] + 0xc);
          iVar6 = 0;
        }
        FUN_00514640(param_1,param_3,puVar3,iVar6,0,0,0,uVar8,uVar5);
        break;
      }
      param_4 = param_4 + 1;
      iVar6 = iVar6 + 1;
    } while (iVar6 < (int)puVar3[0x19]);
  }
  iVar6 = puVar3[0x19];
  if (((iVar6 != 0) && (puVar3[4] == 0)) && (*(int *)(puVar3[1] + 0x38) == puVar3[2])) {
    iVar2 = puVar3[iVar6 + 0x14];
    puVar3[0x19] = iVar6 + -1;
    if (iVar6 + -1 == 0) {
      if (*(byte *)(param_3 + 0x138) == 0xff) {
        iVar6 = 0;
      }
      else {
        iVar6 = (uint)*(byte *)(param_3 + 0x138) * 0xa4 + *(int *)(param_1 + 0x18);
      }
      uVar5 = *(undefined4 *)(iVar2 + 0x14);
      uVar8 = *puVar3;
    }
    else {
      uVar5 = *(undefined4 *)(iVar2 + 0x14);
      uVar8 = *(undefined4 *)(puVar3[iVar6 + 0x13] + 0xc);
      iVar6 = 0;
    }
    FUN_00514640(param_1,param_3,puVar3,iVar6,0,0,0,uVar8,uVar5);
  }
  if (puVar3[4] == 0) {
    bVar7 = false;
    if (puVar3[2] != 0) goto LAB_0052ce56;
    iVar6 = FUN_004f1440(puVar3[1] + 0x10);
    if (iVar6 != 0) {
      if ((puVar3[0x14] & 4) == 0) {
        *(undefined2 *)((int)puVar3 + 0xb2) = 0;
      }
      puVar3[0x14] = puVar3[0x14] & 0xfffffffb;
      puVar3[2] = iVar6;
      puVar3[3] = 0;
      puVar3[4] = 0;
      *(undefined1 *)(puVar3 + 0xe) = 1;
      FUN_00514550();
    }
  }
  else {
    if ((puVar3[0x14] & 4) == 0) {
      *(undefined2 *)((int)puVar3 + 0xb2) = 0;
    }
    puVar3[0x14] = puVar3[0x14] & 0xfffffffb;
    puVar3[2] = puVar3[4];
    puVar3[3] = 0;
    puVar3[4] = 0;
    *(undefined1 *)(puVar3 + 0xe) = 1;
    FUN_00514550();
    puVar3[4] = 0;
  }
  bVar7 = puVar3[2] == 0;
LAB_0052ce56:
  if (!bVar7) {
    iVar6 = puVar3[3];
    while (iVar6 != 0) {
      uVar5 = 0;
      iVar6 = puVar3[3];
      if ((*(int *)(iVar6 + 0x10) == 0) || (*(int *)(*(int *)(iVar6 + 0x10) + 4) == 0)) {
        puVar3[0x14] = puVar3[0x14] & 0xfffffffe;
      }
      else {
        if ((*(byte *)(puVar3 + 0x14) & 1) != 0) {
          puVar3[0x1c] = 0;
          *(undefined1 *)(puVar3 + 0x1a) = 0;
          puVar3[0x1d] = 0;
          *(undefined1 *)((int)puVar3 + 0x69) = 0;
          puVar3[0x27] = 0;
          puVar3[0x1b] = 0;
          *(undefined2 *)((int)puVar3 + 0x6a) = 0;
          *(undefined2 *)((int)puVar3 + 0xb6) = 0;
          puVar3[0x20] = 0;
          puVar3[0x1f] = 0;
          puVar3[0x1e] = 0;
          puVar3[0x21] = 0;
          puVar3[0x22] = 0;
          puVar3[0x23] = 0;
          puVar3[0x24] = 0;
          puVar3[0x25] = 0;
          puVar3[0x26] = 0;
          if (param_3 != 0) {
            *(undefined4 *)(param_3 + 0x180) = 0;
            *(undefined1 *)(param_3 + 0x13f) = 0;
            *(undefined4 *)(param_3 + 0x17c) = 0;
            *(undefined4 *)(param_3 + 0x1e4) = 0;
            if (DAT_009238ac != (code *)0x0) {
              (*DAT_009238ac)(param_1,param_3,puVar3);
            }
          }
          puVar3[0x14] = puVar3[0x14] & 0xfffffffe;
          uVar5 = 1;
          if (*(char *)(*(int *)(iVar6 + 0x10) + 8) != '\0') {
            FUN_0053db30(iVar6,param_3);
          }
        }
        iVar6 = (**(code **)(*(int *)(iVar6 + 0x10) + 4))
                          (param_1,puVar3,param_3,*(undefined4 *)(iVar6 + 8),
                           *(undefined4 *)(iVar6 + 0xc),uVar5,param_5);
        if (iVar6 == 0) break;
      }
      if ((*(byte *)(puVar3 + 0x14) & 1) == 0) {
        if (puVar3[3] == 0) {
          iVar6 = FUN_004f1440(puVar3[2] + 0x10);
        }
        else {
          iVar6 = FUN_004f1460(puVar3[2] + 0x10,puVar3[3]);
        }
        if (iVar6 == 0) {
          puVar3[3] = 0;
        }
        else {
          puVar3[0x14] = puVar3[0x14] | 1;
          puVar3[3] = iVar6;
        }
      }
      iVar6 = puVar3[3];
    }
  }
  iVar6 = FUN_0052caf0(param_1,param_3);
  if (iVar6 == 0) {
    fVar1 = (float)puVar3[0x2e];
    if (0.0 < (float)puVar3[0x2e]) {
      puVar3[0x2e] = (float)puVar3[0x2e] - param_5;
    }
    if (((0.0 < fVar1) && ((float)puVar3[0x2e] <= 0.0)) && (puVar3[0x2f] != 0)) {
      FUN_005145a0(puVar3,puVar3[0x2f]);
      puVar3[0x2f] = 0;
      *(undefined1 *)(puVar3 + 0x2d) = 0;
      return;
    }
    if ((puVar3[2] != 0) && (iVar6 = FUN_0052c880(param_1,puVar3[2] + 8,param_3,puVar3), iVar6 != 0)
       ) {
      puVar3[0x14] = puVar3[0x14] ^ ((uint)*(ushort *)(iVar6 + 0xe) * 2 ^ puVar3[0x14]) & 4;
      FUN_005145a0(puVar3,*(undefined4 *)(iVar6 + 0x24));
    }
  }
  return;
}

