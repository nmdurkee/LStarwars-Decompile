/* ev_00be516cc2c5d610e5e2c0bc97f4389d72f922b15f1750af22dd06fd6156e83b */

void FUN_004fb130(void)

{
  char *pcVar1;
  bool bVar2;
  char cVar3;
  int iVar4;
  undefined4 uVar5;
  int *piVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  undefined *puVar11;
  int iVar12;
  undefined4 *puVar13;
  int local_8;
  
  local_8 = -1;
  iVar4 = FUN_006d60a0();
  iVar9 = DAT_0080051c;
  iVar12 = 0;
  if (0 < iVar4) {
    puVar11 = &DAT_0091707c;
    do {
      pcVar1 = puVar11 + -0x7c;
      cVar3 = FUN_006dae50(iVar12,puVar11 + -0x74,puVar11 + -0x73,puVar11 + -0x72,puVar11 + -0x71,
                           puVar11 + -0x70,puVar11 + -0x6f,puVar11 + -0x6e,puVar11 + -0x6d,
                           puVar11 + -0x6c,puVar11,puVar11 + -0x5c);
      *pcVar1 = cVar3;
      FUN_004f4cf0(pcVar1);
      if (*pcVar1 != '\0') {
        uVar5 = FUN_006d9370(iVar12);
        *(undefined4 *)(puVar11 + -0x48) = uVar5;
      }
      FUN_004f4370(pcVar1);
      iVar12 = iVar12 + 1;
      puVar11 = puVar11 + 0x84;
    } while (iVar12 < iVar4);
  }
  if (DAT_0297dc20 == 1) {
    if (DAT_0297dc08 == 1) {
      FUN_004fadd0(DAT_0297dc1c);
    }
    else if (DAT_0297dc08 == 2) {
      DAT_0297dc08 = 0;
      DAT_0297dc14 = DAT_0297dc0c;
    }
    DAT_0297dc20 = 0;
  }
  iVar12 = 0;
  if (0 < iVar4) {
    puVar13 = &DAT_00917004;
    do {
      bVar2 = false;
      if (iVar9 < 1) {
LAB_004fb23b:
        *puVar13 = 0xffffffff;
      }
      else {
        piVar6 = &DAT_0297e044;
        iVar8 = iVar9;
        do {
          if ((piVar6[1] != 0) && (iVar12 == *piVar6)) {
            bVar2 = true;
          }
          piVar6 = piVar6 + 3;
          iVar8 = iVar8 + -1;
        } while (iVar8 != 0);
        if (!bVar2) goto LAB_004fb23b;
      }
      iVar12 = iVar12 + 1;
      puVar13 = puVar13 + 0x21;
    } while (iVar12 < iVar4);
  }
  if (DAT_0091ef30 == 0) {
    iVar9 = -1;
    iVar12 = 0;
    DAT_0297e044 = -1;
    if (0 < iVar4) {
      piVar6 = &DAT_00917010;
      do {
        if ((char)piVar6[-4] != '\0') {
          if (iVar9 == -1) {
            piVar6[-3] = 0;
            iVar9 = iVar12;
          }
          if ((((*piVar6 != 0) || ((char)piVar6[-2] != -0x80)) ||
              ((*(char *)((int)piVar6 + -7) != -0x80 ||
               ((*(char *)((int)piVar6 + -6) != -0x80 || (*(char *)((int)piVar6 + -5) != -0x80))))))
             && (piVar6[-3] = 0, iVar9 = iVar12, (piVar6[1] & 0x840U) != 0)) {
            DAT_0297e044 = iVar12;
            return;
          }
        }
        iVar12 = iVar12 + 1;
        piVar6 = piVar6 + 0x21;
        DAT_0297e044 = iVar9;
      } while (iVar12 < iVar4);
    }
  }
  else {
    iVar12 = 0;
    if (0 < iVar9) {
      do {
        if ((((&DAT_0297e048)[iVar12 * 3] == 1) &&
            ((&DAT_00917000)[(&DAT_0297e044)[iVar12 * 3] * 0x84] == '\0')) && (iVar8 = 0, 0 < iVar4)
           ) {
          piVar6 = &DAT_00917004;
          do {
            if ((((char)piVar6[-1] != '\0') && ((piVar6[4] & 0x800U) != 0)) &&
               ((*piVar6 == -1 || ((&DAT_0297e048)[*piVar6 * 3] == 0)))) {
              (&DAT_0297e044)[iVar12 * 3] = iVar8;
              (&DAT_00917004)[iVar8 * 0x21] = iVar12;
              (&DAT_00917014)[iVar8 * 0x21] = 0;
              goto LAB_004fb471;
            }
            iVar8 = iVar8 + 1;
            piVar6 = piVar6 + 0x21;
          } while (iVar8 < iVar4);
        }
        if ((&DAT_0297e048)[iVar12 * 3] == 0) {
          (&DAT_0297e044)[iVar12 * 3] = 0xffffffff;
          if (DAT_0297e054 + DAT_0297e048 == 0) {
            if ((iVar12 == 0) && (0 < iVar4)) {
              piVar6 = &DAT_00917004;
              iVar8 = iVar4;
              do {
                if ((*piVar6 == -1) || ((&DAT_0297e048)[*piVar6 * 3] != 1)) {
                  *piVar6 = -1;
                }
                piVar6 = piVar6 + 0x21;
                iVar8 = iVar8 + -1;
              } while (iVar8 != 0);
            }
          }
          else if (0 < iVar4) {
            piVar6 = &DAT_00917004;
            iVar8 = iVar4;
            do {
              if ((*piVar6 == -1) || ((&DAT_0297e048)[*piVar6 * 3] != 1)) {
                *piVar6 = -1;
              }
              piVar6 = piVar6 + 0x21;
              iVar8 = iVar8 + -1;
            } while (iVar8 != 0);
          }
          iVar8 = 0;
          if (0 < iVar4) {
            iVar7 = 0;
            iVar10 = local_8 * 0x84;
            do {
              if ((*(int *)((int)&DAT_00917004 + iVar7) == -1) && ((&DAT_00917000)[iVar7] != '\0'))
              {
                (&DAT_0297e044)[iVar12 * 3] = iVar8;
                *(int *)((int)&DAT_00917004 + iVar7) = iVar12;
                if (-1 < local_8) {
                  *(undefined4 *)((int)&DAT_00917004 + iVar10) = 0xffffffff;
                }
                local_8 = iVar8;
                if ((((*(int *)((int)&DAT_00917010 + iVar7) != 0) ||
                     ((&DAT_00917008)[iVar7] != -0x80)) || ((&DAT_00917009)[iVar7] != -0x80)) ||
                   (((&DAT_0091700a)[iVar7] != -0x80 ||
                    (iVar10 = iVar7, (*(uint *)((int)&DAT_00917014 + iVar7) & 0x840) != 0)))) break;
              }
              iVar8 = iVar8 + 1;
              iVar7 = iVar7 + 0x84;
            } while (iVar8 < iVar4);
          }
        }
LAB_004fb471:
        iVar12 = iVar12 + 1;
        if (iVar9 <= iVar12) {
          return;
        }
      } while( true );
    }
  }
  return;
}

