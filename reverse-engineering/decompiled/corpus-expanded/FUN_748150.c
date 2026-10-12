/* Ghidra pseudocode, not original source.
 * ev_bef7beff20bbab7c70650c6f9f545113d8e67786c96c5ee03f6ff15c7c5049ec
 * Entry: 0x748150; label: FUN_00748150
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00748150(undefined4 *param_1,int param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  char cVar5;
  int iVar6;
  undefined4 uVar7;
  int in_ECX;
  undefined1 *puVar8;
  undefined4 *puVar9;
  
  iVar4 = param_2;
  uVar2 = *(undefined4 *)(in_ECX + 0x99c);
  *(int *)(in_ECX + 0x99c) = param_2;
  puVar9 = param_1;
  if (param_1 == (undefined4 *)0x0) {
    *(undefined4 *)(in_ECX + 0x99c) = uVar2;
    return;
  }
  do {
    switch(*puVar9) {
    case 0:
      cVar5 = FUN_00746f10(puVar9[4],&param_1);
      if ((cVar5 == '\0') || (param_1 == (undefined4 *)0x0)) {
        if (puVar9[3] != 0) {
          FUN_00748150(puVar9[3],iVar4);
        }
      }
      else {
        FUN_00748150(puVar9[2],iVar4);
      }
      break;
    case 1:
      FUN_00747320(puVar9[2],puVar9[3],0);
      if ((*(char *)(in_ECX + 0x965) == '\0') && (iVar4 != 0)) {
        puVar8 = (undefined1 *)puVar9[3];
        if (puVar8 == (undefined1 *)0x0) {
          puVar8 = &DAT_007516c0;
        }
        FUN_007486b0("#define ");
        FUN_007486b0(puVar9[2]);
        FUN_007486b0(&DAT_007596f8);
LAB_0074822d:
        FUN_007486b0(puVar8);
        FUN_007486b0(&DAT_0076aa4c);
      }
      break;
    case 2:
      if (iVar4 != 0) {
        FUN_007486b0("#undef ");
        puVar8 = (undefined1 *)puVar9[2];
        goto LAB_0074822d;
      }
      break;
    case 3:
      iVar6 = FUN_00746cb0(puVar9[5],puVar9[2]);
      if (iVar6 == 0) {
        param_2 = FUN_007464c0(puVar9[5],in_ECX + 0x954);
        if (puVar9[7] == 0) {
          uVar7 = 0;
        }
        else {
          uVar7 = FUN_007464c0(puVar9[7],in_ECX + 0x954);
        }
        iVar6 = *(int *)(in_ECX + 0x958);
        *(int *)(in_ECX + 0x958) = iVar6 + 0x24;
        if (iVar6 == 0) {
          FUN_00746c20(0);
        }
        else {
          uVar7 = FUN_00746520(puVar9[2],puVar9[3],puVar9[4],param_2,puVar9[6],uVar7,puVar9[8],
                               puVar9[9]);
          FUN_00746c20(uVar7);
        }
      }
      break;
    case 4:
      uVar7 = puVar9[4];
      iVar6 = puVar9[3];
      if (0 < (int)puVar9[3]) {
        do {
          param_2 = iVar6;
          iVar6 = FUN_00746bb0(uVar7);
          param_2 = param_2 + -1;
          uVar7 = *(undefined4 *)(iVar6 + 4);
          iVar6 = param_2;
        } while (param_2 != 0);
      }
      iVar6 = FUN_00746cb0(uVar7,puVar9[2]);
      if ((iVar6 != 0) ||
         ((((uint)puVar9[2] >> 5 & 1) != 0 && (iVar6 = FUN_00746d20(uVar7), iVar6 != 0)))) {
        *(int *)(iVar6 + 0x20) = *(int *)(iVar6 + 0x20) + 1;
        uVar7 = FUN_00746a00(iVar6);
        FUN_00747320(uVar7,0,0);
      }
      break;
    case 5:
      *(bool *)(in_ECX + 0x965) = *(char *)(puVar9 + 2) == '\0';
      break;
    case 6:
      if (iVar4 != 0) {
        uVar3 = puVar9[2];
        if ((uVar3 >> 5 & 1) == 0) {
          if (uVar3 == 0x2010) {
            FUN_00747760(iVar4);
          }
          else if (uVar3 == 0x3008) {
            FUN_007478c0(iVar4);
          }
          else if (uVar3 == 0x2002) {
            FUN_00747f50(iVar4);
          }
          else if (uVar3 == 0x1004) {
            FUN_00748030(iVar4);
          }
        }
        else {
          FUN_00747440(iVar4);
        }
      }
      break;
    case 7:
      if (iVar4 != 0) {
        FUN_00748530(puVar9[2],puVar9[3]);
      }
    }
    puVar1 = puVar9 + 1;
    puVar9 = (undefined4 *)*puVar1;
    if ((undefined4 *)*puVar1 == (undefined4 *)0x0) {
      *(undefined4 *)(in_ECX + 0x99c) = uVar2;
      return;
    }
  } while( true );
}

