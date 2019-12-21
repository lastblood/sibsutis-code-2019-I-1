<xsl:stylesheet version="2.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">

    <xsl:template match="/">
        <html>
            <head>
                <title>РГЗ</title>
            </head>
            <body>
                <h2>РГЗ</h2>
                <h3>Выполнил: Ханов Ян Тимурович</h3>
                <h3>Группа: ИС-941</h3>
                <h3>Вариант: 4</h3>
                <hr/>
                <xsl:apply-templates/>
            </body>
        </html>
    </xsl:template>

    <xsl:template match="hiblock">
        <xsl:apply-templates/>
    </xsl:template>

    <xsl:template match="page">
        <hr/>
        <h2>Станица <xsl:value-of select="@num"/></h2>
        <hr/>

        <xsl:value-of select="name"/><br/><br/>

        <xsl:if test="@num = 0">
            <xsl:apply-templates select="//sequence" />
        </xsl:if>

        <xsl:if test="@num = 1">
            <xsl:apply-templates select="table" />
        </xsl:if>

        <xsl:if test="@num = 2">
            <xsl:apply-templates select="countries"/>
        </xsl:if>
    </xsl:template>

    <xsl:template match="sequence">
        <xsl:if test="@variant=4">

            <h3><xsl:value-of select="name"/> </h3>
            <table border="1" cellpadding="8">
                <tr>
                    <th>N</th>
                    <xsl:for-each select="items/item">
                        <th style="color:white" bgcolor="{num/@color}">
                            <xsl:value-of select="num"/>
                        </th>
                    </xsl:for-each>
                </tr>
                <tr>
                    <th>Значение</th>
                    <xsl:for-each select="items/item">
                        <th align="center">
                            <xsl:value-of select="val"/>
                        </th>
                    </xsl:for-each>
                </tr>
            </table>
        </xsl:if>
    </xsl:template>

    <xsl:template match="table">
        <xsl:variable name="size" select="@row-size"/>
        <table border="0" cellspacing="0" cellpadding="0">
            <xsl:for-each select="item">
                <xsl:sort select="order" order="descending" data-type="number"/>

                <xsl:if test="order &lt; $size + 1"> <!-- 1 2 3 4 5 6 7 -->
                    <xsl:variable name="current" select="order - 1"/> <!-- 0 1 2 3 4 5 6 -->

                    <tr>
                        <xsl:for-each select="//table/item">
                            <xsl:sort select="order" order="descending" data-type="number"/>
                            <!-- 0 -> 1 2 3 4 5 6 7 -->
                            <!-- 1 -> 8 9 10 11 12 13 14 -->
                            <xsl:if test="order &gt; $size*$current">
                                <xsl:if test="order &lt; $size*($current + 1) + 1">
                                    <td>
                                        <img style="display:block" src="{url}"/>
                                    </td>
                                </xsl:if>
                            </xsl:if>
                        </xsl:for-each>
                    </tr>
                </xsl:if>
            </xsl:for-each>
        </table>
    </xsl:template>

    <xsl:template match="countries">
        <table border="1px" bordercolor="black">
            <xsl:for-each select="country">
                <xsl:sort select="id" data-type="number"/>
                <tr>
                    <td><xsl:value-of select="id"/></td>
                    <td><xsl:value-of select="uf_name"/> </td>
                    <td><img src="{uf_icon}"/> </td>
                </tr>
            </xsl:for-each>
        </table>
    </xsl:template>
</xsl:stylesheet>