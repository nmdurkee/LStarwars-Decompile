/* Ghidra pseudocode, not original source.
 * ev_9d34c938d292037f498e462893e532f4f6f058923093d2cacbd29fd836aaae04
 * Entry: 0x507390; label: FUN_00507390
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00507390(undefined4 *param_1,int param_2,int param_3)

{
  uint *puVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  bool bVar5;
  undefined4 uVar6;
  undefined1 local_c [4];
  int local_8;
  
  piVar4 = DAT_009213d8;
  do {
    if (param_1 == (undefined4 *)0x0) {
      DAT_009213d8 = piVar4;
      return;
    }
    bVar5 = false;
    DAT_009213d8 = piVar4;
    switch(param_1[1]) {
    case 0:
      iVar2 = FUN_005004e0(param_1[2]);
      bVar5 = iVar2 != 0;
      if (bVar5) {
        FUN_00505f20(iVar2);
      }
      uVar6 = param_1[2];
      break;
    case 1:
      iVar2 = FUN_005004e0(param_1[2]);
      bVar5 = iVar2 != 0;
      if (bVar5) {
        FUN_00506030(iVar2,param_1[3]);
      }
      if (param_1[3] == 0) goto LAB_005074cd;
      goto LAB_00507408;
    case 2:
      iVar2 = FUN_005004e0(param_1[2]);
      iVar3 = FUN_005004e0(param_1[3]);
      if ((iVar2 != 0) && (iVar3 != 0)) {
        if (*(int *)(iVar2 + 0x58) == 0) {
          iVar3 = FUN_004fff00();
        }
        *(int *)(iVar2 + 0xb0) = iVar3;
LAB_0050745b:
        bVar5 = true;
      }
      goto LAB_00507460;
    case 3:
      iVar2 = FUN_005004e0(param_1[2]);
      if (iVar2 != 0) {
        iVar3 = param_1[3];
        if (0x1f < iVar3) {
          iVar2 = FUN_004fff10(iVar3);
          iVar3 = 0x1f;
        }
        *(uint *)(iVar2 + 0x88) =
             *(uint *)(iVar2 + 0x88) ^ (iVar3 << 0xd ^ *(uint *)(iVar2 + 0x88)) & 0x3e000;
        goto LAB_0050745b;
      }
      goto LAB_00507460;
    case 4:
      iVar2 = FUN_005004e0(param_1[2]);
      if (iVar2 != 0) {
        FUN_00505e50(iVar2);
        bVar5 = true;
      }
LAB_005074cd:
      uVar6 = param_1[2];
      break;
    case 5:
      bVar5 = param_3 != 0;
      if (bVar5) {
        FUN_00505590(param_3,param_1[3],(int)*(char *)(param_1 + 2),(int)*(char *)((int)param_1 + 9)
                    );
      }
      if (*(char *)((int)param_1 + 9) == '\0') {
        FUN_004fff10((int)*(char *)(param_1 + 2),param_1[3]);
      }
      else {
        FUN_004fff10((int)*(char *)(param_1 + 2),param_1[3]);
      }
      goto LAB_00507414;
    case 6:
      if (param_3 == 0) goto LAB_005074cd;
      FUN_00505710(param_3,param_1[2]);
      uVar6 = param_1[2];
      bVar5 = true;
      break;
    case 7:
      if ((param_2 != 0) && (iVar2 = FUN_005cf5b0(param_2,local_c,param_1[3],1), iVar2 != 0)) {
        if (*(char *)(param_1 + 2) != '\0') {
          puVar1 = (uint *)(*(int *)(local_8 + 0x40) + 0x44);
          *puVar1 = *puVar1 | 1;
          uVar6 = param_1[3];
          bVar5 = true;
          break;
        }
        puVar1 = (uint *)(*(int *)(local_8 + 0x40) + 0x44);
        *puVar1 = *puVar1 & 0xfffffffe;
        bVar5 = true;
      }
      uVar6 = param_1[3];
      break;
    case 8:
      iVar2 = param_1[2];
      if ((iVar2 < 0x20) && ((int)*(char *)(iVar2 + 0x18 + param_3) == param_1[3])) {
        FUN_004fff10(iVar2,param_1[3]);
        FUN_00507390(param_1[4],param_2,param_3);
      }
      else {
        FUN_004fff10(iVar2,param_1[3]);
        FUN_00507390(param_1[5],param_2,param_3);
      }
      goto switchD_005073b1_default;
    case 9:
      if ((int)param_1[2] < 0x20) {
        *(undefined1 *)(param_1[2] + 0x18 + param_3) = *(undefined1 *)(param_1 + 3);
        goto LAB_0050745b;
      }
LAB_00507460:
      FUN_004fff10(param_1[2],param_1[3]);
      goto LAB_00507414;
    case 10:
      iVar2 = FUN_00505650(param_3,param_1[2]);
      if (iVar2 == 0) {
        FUN_004fff10(param_1[2]);
        FUN_00507390(param_1[4],param_2,param_3);
      }
      else {
        FUN_004fff10(param_1[2]);
        FUN_00507390(param_1[3],param_2,param_3);
      }
      goto switchD_005073b1_default;
    case 0xb:
      FUN_00505600(param_3,param_1[2]);
      FUN_004fff10(param_1[2]);
      goto LAB_0050741d;
    case 0xc:
      iVar2 = FUN_005004e0(param_1[2]);
      if (iVar2 == 0) goto LAB_005074cd;
      *(uint *)(iVar2 + 0x88) = *(uint *)(iVar2 + 0x88) | 4;
      uVar6 = param_1[2];
      bVar5 = true;
      break;
    case 0xd:
      iVar2 = FUN_005004e0(param_1[2]);
      if (iVar2 != 0) {
        *(uint *)(iVar2 + 0x88) = *(uint *)(iVar2 + 0x88) & 0xfffffffb;
        bVar5 = true;
      }
LAB_00507408:
      uVar6 = param_1[2];
      break;
    case 0xe:
      FUN_004fff10(*piVar4);
      do {
        if (*piVar4 == 0) break;
        iVar2 = FUN_004f8b10(param_1[2],*piVar4);
        if (iVar2 == 0) {
          if ((code *)piVar4[1] != (code *)0x0) {
            (*(code *)piVar4[1])(param_1[3]);
            goto LAB_0050741d;
          }
          break;
        }
        piVar4 = piVar4 + 2;
      } while (piVar4 != (int *)0x0);
    default:
      goto switchD_005073b1_default;
    }
    FUN_004fff10(uVar6);
LAB_00507414:
    if (!bVar5) {
switchD_005073b1_default:
      FUN_004fff10();
    }
LAB_0050741d:
    param_1 = (undefined4 *)*param_1;
    piVar4 = DAT_009213d8;
  } while( true );
}

